/*
 * SDLInterface.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */
#include "SDLInterface.h"
#include "SDL2/SDL.h"
#include "Game.h"
#include "Animation.h"
#include <fstream>
#include "Tileset.h"
#include "Tile.h"
#include <vector>
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
SDLInterface::SDLInterface(Game* game, int w, float r) : game(game) {
	resolution=r;
	width=w;
	height=width/resolution;
}

int SDLInterface::CloseGraphics() {
	SDL_DestroyTexture(screenTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}
SDLInterface::~SDLInterface() {
}

int SDLInterface::InitGraphics() {
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) return 1;
	window = SDL_CreateWindow("Generic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if( window == NULL ) return 2;
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) return 3;
	screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
	if (screenTexture==NULL) return 4;
	pixels = new unsigned int[width * height];
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			pixels[width*j+i]=(255<<24);
		}
	}
	return 0;
}

InputState SDLInterface::EventPoll() {
	SDL_Event e;
	SDL_PumpEvents();
	InputState state = InputState();
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			state.quit=true;
		}
	}
	return state;
}

void SDLInterface::WritePixel(unsigned int data, int x, int y) {
	if (x>width || x<0 || y>height || y<0) return;
	if ((data>>24)==0) return;
	else {
		pixels[y*width+x]=data;
	}
}

void SDLInterface::UpdateGraphics() {
	SDL_UpdateTexture(screenTexture, NULL, pixels, width * sizeof(unsigned int));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

Animation* SDLInterface::LoadAnimation(char* path, char* key) {
	std::cout<<"Loading "<<key<<"..."<<std::flush;
	char header[3];
		char palette[4];
		char smallHeader[2];
		char buffer[1];
		char** data;
		std::string pth = std::string(path);
		std::map<std::string, Animation*>::iterator it=anims.find(std::string(key));
		if (it!=anims.end()) return it->second;
		Animation* anim = new Animation();
		std::ifstream file (path, std::ios::in | std::ios::binary);
		file.read(header, 3);
		//std::cout<<"\n"<<(int) header[0]<<" "<<(int) header[1]<<" "<<(int) header[2]<<"\n"<<std::flush;
		anim->interval=header[1];
		for (int i=0; i<header[2];i++) {
			file.read(palette, 4);
			anim->SetPalette(i, (palette[0]<<24)+(palette[1]<<16)+(palette[2]<<8)+palette[3]);
			//std::cout<<"\n"<<hex(palette[0])<<" "<<hex(palette[1])<<" "<<hex(palette[2])<<" "<<hex(palette[3])<<"\n"<<std::flush;
			//std::cout<<"\n"<<(palette[0]<<24)+(palette[1]<<16)+(palette[2]<<8)+palette[3]<<"\n"<<std::flush;
		}
		for (int k=0; k<header[0];k++) {
			file.read(smallHeader, 2);
			data=new char*[smallHeader[0]];
			for(int i = 0; i < smallHeader[0]; ++i) data[i] = new char[smallHeader[1]];
			for (int i = 0; i <smallHeader[0]; i++) {
				for (int j = 0; j<smallHeader[1]; j++) {
					file.read(buffer, 1);
					if (buffer[0]!=0) {
					}
					data[j][i]=buffer[0];
				}
			}
			anim->AddFrame(data, smallHeader[0], smallHeader[1]);
		}
		anims.insert(std::pair<std::string, Animation*>(key, anim));
		std::cout<<"Done.\n"<<std::flush;
		return anim;
}

Tileset* SDLInterface::LoadTileset(char* path, char* key) {
	std::cout<<"Loading "<<key<<"..."<<std::flush;
	char header[4];
	char palette[4];
	char buffer[1];
	std::string pth = std::string(path);
	std::map<std::string, Tileset*>::iterator it=sets.find(std::string(key));
	if (it!=sets.end()) return it->second;
	std::ifstream file (path, std::ios::in | std::ios::binary);
	file.read(header, 4);
	Tileset* tileset = new Tileset(header[0], header[1], header[3]);
	for (int i=0; i<header[3];i++) {
		file.read(palette, 4);
		tileset->SetPalette(i, (palette[0]<<24)+(palette[1]<<16)+(palette[2]<<8)+palette[3]);
	}
	char** data=new char*[header[0]];

	for(int i = 0; i < header[0]; ++i) data[i] = new char[header[1]];
	for (int j = 0; j<header[1]; j++) {
		for (int i = 0; i <header[0]; i++) {
			file.read(buffer, 1);
			data[i][j]=buffer[0];
		}
	}

	tileset->CopyData(data);
	int k=0;
	for (int j = 0; j<header[1]/header[2]; j++) {
		for (int i = 0; i<header[0]/header[2]; i++) {
			file.read(buffer, 1);

			switch (buffer[0]) {
			case 0:
				tileset->tiles[k]=new Tile(i*header[2], j*header[2], new AABB(header[2]/2, header[2]/2), 0, new CollisionInfo());
				k++;
				break;
			case 1:
				tileset->tiles[k]=new Tile(i*header[2], j*header[2], new AABB(header[2]/2, header[2]/2), SOLID, new CollisionInfo());
				k++;
				break;
			default:
				throw('a');
				break;
			}
		}
	}
	std::cout<<"Done.\n"<<std::flush;
	return tileset;
}

void SDLInterface::BeginGraphics() {
	if (width!=game->Camera().w || height!=game->Camera().h) {
		width=game->Camera().w;
		height=game->Camera().h;
		SDL_DestroyTexture(screenTexture);
		screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
		if (screenTexture==NULL) throw(4);
	}
	pixels = new unsigned int[width * height];
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			pixels[width*j+i]=(255<<24);
		}
	}
}

Animation* SDLInterface::GetAnimation(char* key) {
	auto it=anims.find(std::string(key));
	if (it!=anims.end()) return it->second;
	return 0;
}

Tileset* SDLInterface::GetTileset(char* key) {
	auto it=sets.find(std::string(key));
	if (it!=sets.end()) return it->second;
	return 0;
}

void SDLInterface::ConvertSprite(char* inPath, char* outPath) {
	SDL_Surface* surface = SDL_LoadBMP(inPath);
	SDL_LockSurface(surface);
	char buffer[1];
	char palette[4];
	char* data = new char[(surface->w)*(surface->h)];
	std::vector<int> palettes;
	int palettesSet=0;
	for (int i=0; i<surface->w; i++) {
		for (int j=0;j<surface->h; j++) {
			unsigned int pixel = getpixel(surface, i, j);

			for (int k=0; k<palettesSet+1; k++) {
				if (k==palettesSet) {
					palettes.push_back(pixel);
					data[j*(surface->w)+i]=k;
					palettesSet++;
					break;
				}
				else {
					if (palettes[k]==pixel) {
						if (k==0) {
							std::cout<<i<<","<<j<<"-"<<std::hex<<pixel<<std::dec<<"\n"<<std::flush;
						}
						data[j*(surface->w)+i]=k;
						break;
					}
				}
			}
		}
	}
	std::ofstream file (outPath, std::ios::out | std::ios::binary);
	buffer[0]=surface->w;
	file.write(buffer, 1);
	buffer[0]=surface->h;
	file.write(buffer, 1);
	buffer[0]=palettesSet;
	file.write(buffer, 1);
	for (int i=0; i<palettesSet; i++) {
		int n = palettes[i];
		palette[0] = (n >> 24) & 0xFF;
		palette[1] = (n >> 16) & 0xFF;
		palette[2] = (n >> 8) & 0xFF;
		palette[3] = n & 0xFF;
		file.write(palette, 4);
	}
	file.write(data, (surface->w)*(surface->h));

}
