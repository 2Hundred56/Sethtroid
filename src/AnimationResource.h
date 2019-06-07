/*
 * AnimationResource.h
 *
 *  Created on: Jun 6, 2019
 *      Author: triforce
 */

#ifndef ANIMATIONRESOURCE_H_
#define ANIMATIONRESOURCE_H_

#include "Sprite.h"
struct Frame {
	char** data;
	int w;
	int h;
	Frame(char** d, int w, int h) : data(d), w(w), h(h) {

	}
	Frame() {

	}
};

class AnimationResource: public Sprite {
public:
	AnimationResource() : Sprite(0, 0) {
		frames = new Frame[16];
	}
	virtual ~AnimationResource() {

	}
	int GetWidth(int index) {
		return frames[index].w;
	}
	int GetHeight(int index) {
		return frames[index].h;
	}
	unsigned int PixelAt(int index, int x, int y) {
		if (!HFLIPPED) {
			return palettes[frames[index].data[x][y]];
		}
		else {
			return palettes[frames[index].data[width-x-1][y]];
		}
	}
	void AddFrame(char** data, int w, int h) {
		frames[numFrames]=Frame(data, w, h);
		numFrames++;
	}
	char GetData(int index, int x, int y) {
		if (!HFLIPPED) {
			return frames[index].data[x][y];
		}
		else {
			return frames[index].data[width-x-1][y];
		}
	}
	Frame* frames;
	int interval = 1;
	int numFrames = 0;

};

#endif
