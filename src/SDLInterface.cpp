/*
 * SDLInterface.cpp
 *
 *  Created on: May 31, 2019
 *      Author: triforce
 */

#include "SDLInterface.h"
#include <iostream>
#include <fstream>
const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 512;
unsigned int getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;
    }
}
SDLInterface::SDLInterface() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

SDLInterface::~SDLInterface() {
}
int SDLInterface::InitGraphics() {
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) return 1;
	window = SDL_CreateWindow("Generic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if( window == NULL ) return 2;
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) return 3;
	screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (screenTexture==NULL) return 4;
	pixels = new unsigned int[SCREEN_WIDTH * SCREEN_HEIGHT];
	for (int i=0; i<SCREEN_WIDTH; i++) {
		for (int j=0; j<SCREEN_HEIGHT; j++) {
			pixels[SCREEN_WIDTH*j+i]=(255<<24)+(127<<16)+(127<<8)+(127);
		}
	}
	return 0;
}
void SDLInterface::WritePixel(int data, int x, int y) {
	if ((data>>24)==0) return;
	else {
		pixels[y*SCREEN_WIDTH+x]=data;
	}
}
void SDLInterface::BlitSprite(Sprite* sprite, int x, int y) {
	if (x>SCREEN_WIDTH || y>SCREEN_HEIGHT) {
		return;
	}
	for (int i=0; i<sprite->GetWidth(); ++i) {
		for (int j=0; j<sprite->GetHeight(); ++j) {
			WritePixel(sprite->PixelAt(i, j), i+x, j+y);
		}
	}
}
bool SDLInterface::EventPoll() {
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			return false;
		}
	}
	return true;
}
int SDLInterface::CloseGraphics() {
	SDL_DestroyTexture(screenTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}
void SDLInterface::UpdateGraphics() {
	SDL_UpdateTexture(screenTexture, NULL, pixels, SCREEN_WIDTH * sizeof(unsigned int));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
void SDLInterface::BlitLayer(Layer* layer, int ox, int oy) {
	for (int i=0; i<SCREEN_WIDTH; ++i) {
		for (int j=0; j<SCREEN_HEIGHT; ++j) {
			WritePixel(layer->PixelAt(i+ox, j+oy), i, j);
		}
	}
}
Sprite* SDLInterface::loadImage(char* path) {
	SDL_Surface* surface = SDL_LoadBMP(path);
	SDL_LockSurface(surface);
	Sprite* output = new Sprite(surface->w, surface->h);
	int palettesSet=0;
	for (int i=0; i<surface->w; i++) {
		for (int j=0;j<surface->h; j++) {
			unsigned int pixel = getpixel(surface, i, j);
			for (int k=0; k<palettesSet+1; k++) {
				if (k==palettesSet) {
					output->SetPalette(k, pixel);
					output->SetPixel(i, j, k);
					palettesSet++;
					break;
				}
				else {
					if (output->GetPalette(k)==pixel) {
						output->SetPixel(i, j, k);
						break;
					}
				}
			}
		}
	}

	return output;
}

Sprite* SDLInterface::loadSprite(char* path) {
	char header[4];
	char palette[2];
	char data[1];
	std::ifstream file (path, std::ios::in | std::ios::binary);
	file.read (header, 4);
	Sprite* output = new Sprite(header[1], header[2]);
	for (int i = 0; i<header[3]; i++) {
		file.read (palette, 2);
		output->SetPalette(i, palette[0]*256+palette[1]);
	}
	for (int i = 0; i<header[1]; i++) {
		for (int j = 0; j<header[2]; j++) {
			file.read(data, 1);
			output->SetPixel(i, j, data[0]);
		}
	}
}

void SDLInterface::exportSprite(char* path, Sprite* sprite) {
	char header[4];
	header[0]=0;
	header[1]=sprite->GetWidth();
	header[2]=sprite->GetHeight();
	header[3]=sprite->x;
	char data[header[1]*header[2]];
	for (int i = 0; i<header[1]; i++) {
		for (int j = 0; j<header[2]; j++) {
			data[j*header[1]+i]=sprite->GetData(i, j);
		}
	}
	std::ofstream file (path, std::ios::out | std::ios::binary);
	file.write(header, 4);
	file.write(data, header[1]*header[2]);
}
