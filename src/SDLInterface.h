/*
 * SDLInterface.h
 *
 *  Created on: May 31, 2019
 *      Author: triforce
 */

#ifndef SDLINTERFACE_H_
#define SDLINTERFACE_H_
#include "SDL2/SDL.h"
#include "Tileset.h"
#include "Layer.h"
#include "AnimationResource.h"
#include <map>
#include <string>
using namespace std;
class SDLInterface{
public:
	SDLInterface();
	virtual ~SDLInterface();
	virtual int InitGraphics();
	virtual bool EventPoll();
	virtual int CloseGraphics();
	virtual void WritePixel(int data, int x, int y);
	virtual void UpdateGraphics();
	virtual void BlitSprite(Sprite* sprite, int x, int y);
	virtual void BlitLayer(Layer*, int offsetx=0, int offsety=0);
	virtual Sprite* _loadImage(char*);
	virtual Sprite* _loadSprite(char*);
	void _exportSprite(char* path, Sprite* sprite);
	float horizInput;
	bool isJumping;
	bool isRunning;
	void _WriteAnimation(char* path, AnimationResource* animation);
	AnimationResource* _ImportAnimation(char* path, std::forward_list<int> widths, int interval);
	AnimationResource* LoadAnim(char* path);
protected:
	SDL_Texture* screenTexture;
	SDL_Renderer* renderer;
	SDL_Window* window;
	map<string, AnimationResource*> paths;
	unsigned int * pixels;

};

#endif /* SDLINTERFACE_H_ */
