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
}

void SDLInterface::WritePixel(unsigned int data, int x, int y) {
	if (x>width || x<0 || y>height || y<0) return;
	if ((data>>24)==0) return;
	else {
		pixels[y*width+x]=data;
	}
}

void SDLInterface::UpdateGraphics() {
	width=game->Camera().w;
	height=game->Camera().h;
	pixels = new unsigned int[width * height];
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			pixels[width*j+i]=(255<<24);
		}
	}
	SDL_UpdateTexture(screenTexture, NULL, pixels, width * sizeof(unsigned int));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

Animation* SDLInterface::LoadAnimation(char* path, char* key) {
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
		return anim;
}

Tileset* SDLInterface::LoadTileset(char* path, char* key) {
	char header[4];
	char palette[4];
	char buffer[1];
	std::string pth = std::string(path);
	std::map<std::string, Tileset*>::iterator it=sets.find(std::string(key));
	if (it!=sets.end()) return it->second;
	std::ifstream file (path, std::ios::in | std::ios::binary);
	file.read(header, 4);
	Tileset* tileset = new Tileset(header[0], header[1]);
	for (int i=0; i<header[3];i++) {
		file.read(palette, 4);
		tileset->SetPalette(i, (palette[0]<<24)+(palette[1]<<16)+(palette[2]<<8)+palette[3]);
	}
	char** data=new char*[header[0]];
	for(int i = 0; i < header[0]; ++i) data[i] = new char[header[1]];
	for (int i = 0; i <header[0]; i++) {
		for (int j = 0; j<header[1]; j++) {
			file.read(buffer, 1);
			data[j][i]=buffer[0];
		}
	}
	tileset->CopyData(data);

	int k=0;

	for (int i = 0; i<header[0]/header[2]; i++) {
		for (int j = 0; j<header[1]/header[2]; j++) {
			file.read(buffer, 1);
			switch (buffer[0]) {
			case 0:
				tileset->tiles[k]=new Tile(i*header[2], j*header[2], new AABB(header[2]/2, header[2]/2), SOLID, new CollisionInfo());

				k++;
				break;
			default: break;
			}
		}
	}
	return tileset;
}

void SDLInterface::BeginGraphics() {
	width=game->Camera().w;
	height=game->Camera().h;
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
