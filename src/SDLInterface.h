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
#include "Animation.h"
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
	virtual Sprite* loadImage(char*);
	virtual Sprite* loadSprite(char*);
	void exportSprite(char* path, Sprite* sprite);
	float horizInput;
	bool isJumping;
	bool isRunning;
	void WriteAnimation(char* path, Animation* animation);
	Animation* ImportAnimation(char* path, std::forward_list<int> widths, int interval);
protected:
	SDL_Texture* screenTexture;
	SDL_Renderer* renderer;
	SDL_Window* window;
	unsigned int * pixels;

};

#endif /* SDLINTERFACE_H_ */
