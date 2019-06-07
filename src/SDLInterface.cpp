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
Sprite* SDLInterface::_loadImage(char* path) {
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

Sprite* SDLInterface::_loadSprite(char* path) {
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

void SDLInterface::_exportSprite(char* path, Sprite* sprite) {
	char header[4];
	header[0]=0;
	header[1]=sprite->GetWidth();
	header[2]=sprite->GetHeight();
	header[3]=sprite->numPalettes;
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

AnimationResource* SDLInterface::_ImportAnimation(char* path, std::forward_list<int> widths, int interval) {
	SDL_Surface* surface = SDL_LoadBMP(path);
	char**  data;
	Sprite*  output;
	SDL_LockSurface(surface);
	AnimationResource* anim = new AnimationResource();
	anim->interval=interval;
	int palettesSet=0;
	int sum = 0;
	for (auto it = widths.begin(); it!=widths.end(); it++) {
		output = new Sprite(*it, surface->h);
		for (int i=0; i<output->GetWidth(); i++) {
			for (int j=0;j<output->GetHeight(); j++) {
				unsigned int pixel = getpixel(surface, i+sum, j);
				for (int k=0; k<palettesSet+1; k++) {
					if (k==palettesSet) {
						output->SetPalette(k, pixel);
						anim->SetPalette(k, pixel);
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
		data = output->data;
		anim->AddFrame(data, output->GetWidth(), output->GetHeight());
		sum+=*it;
	}
	return anim;
}
void SDLInterface::_WriteAnimation(char* path, AnimationResource* animation) {
	char header[3];
	char palette[4];
	char smallHeader[2];
	std::cout<<animation->frames[0].w;
	header[0]=animation->numFrames;
	header[1]=animation->interval;
	header[2]=animation->numPalettes;
	std::ofstream file (path, std::ios::out | std::ios::binary);
	file.write(header, 3);
	for (int i=0; i<animation->numPalettes; i++) {
		int n = animation->GetPalette(i);
		palette[0] = (n >> 24) & 0xFF;
		palette[1] = (n >> 16) & 0xFF;
		palette[2] = (n >> 8) & 0xFF;
		palette[3] = n & 0xFF;
		file.write(palette, 4);
	}
	for (int i=0; i<animation->numFrames;i++) {
		std::cout<<animation->frames[0].w;
		Frame frame = animation->frames[i];
		smallHeader[0]=frame.w;
		smallHeader[1]=frame.h;
		file.write(smallHeader, 2);
		char data[frame.w*frame.h];
		for (int i = 0; i<smallHeader[0]; i++) {
			for (int j = 0; j<smallHeader[1]; j++) {
				data[j*smallHeader[0]+i]=frame.data[i][j];
			}
		}
		file.write(data, frame.w*frame.h);
	}

}

AnimationResource* SDLInterface::LoadAnim(char* path) {
	char header[3];
	char palette[4];
	char smallHeader[2];
	char buffer[1];
	char** data;
	std::string pth = std::string(path);
	std::map<std::string, AnimationResource*>::iterator it=paths.find(pth);
	if (it!=paths.end()) return it->second;
	AnimationResource* anim;
	std::ifstream file (path, std::ios::in | std::ios::binary);
	file.read(header, 3);
	anim->interval=header[1];
	for (int i=0; i<header[2];i++) {
		file.read(palette, 4);
		anim->SetPalette(i, palette[0]<<24+palette[1]<<16+palette[2]<<8+palette[3]);
	}
	for (int k=0; k<header[0];k++) {
		file.read(smallHeader, 2);
		data=new char*[smallHeader[0]];
		for(int i = 0; i < smallHeader[0]; ++i) data[i] = new char[smallHeader[1]];
		for (int i = 0; i<smallHeader[0]; i++) {
			for (int j = 0; j<smallHeader[1]; j++) {
				file.read(buffer, 1);
				data[i][j]=buffer[0];
			}
		}
		anim->AddFrame(data, smallHeader[0], smallHeader[1]);
	}
	paths.insert(std::pair<std::string, AnimationResource*>(pth, anim));
	return anim;
}
