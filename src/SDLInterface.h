/*
 * SDLInterface.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef SDLINTERFACE_H_
#define SDLINTERFACE_H_

#include "InputTerms.h"
#include <map>
#include <string>

class Tileset;
class Animation;
class Game;
class Sprite;
class SDL_Texture;
class SDL_Renderer;
class SDL_Window;

class SDLInterface {
public:
	SDLInterface(Game*, int width, float resolution);
	virtual ~SDLInterface();
	int InitGraphics();
	int CloseGraphics();
	InputState EventPoll();
	void WritePixel(unsigned int data, int x, int y);
	void BeginGraphics();
	void UpdateGraphics();
	Animation* LoadAnimation(char* path, char* key);
	Tileset* LoadTileset(char* path, char* key);
	Sprite* LoadSprite(char* path, char* key);
	Animation* GetAnimation(char* key);
	Tileset* GetTileset(char* key);
	void ConvertSprite(char* inPath, char* outPath);
protected:
	SDL_Texture* screenTexture;
	SDL_Renderer* renderer;
	SDL_Window* window;
	int width, height;
	float resolution;
	Game* game;
	std::map<std::string, Animation*> anims;
	std::map<std::string, Tileset*> sets;
	unsigned int * pixels;
};



#endif /* SDLINTERFACE_H_ */
