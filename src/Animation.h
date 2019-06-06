/*
 * Animation.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Sprite.h"
struct Frame {
	char** data;
	int w;
	int h;
	Frame(char** d, int w, int h) : data(d), w(w), h(h) {

	}
};
class Animation: public Sprite {
public:
	Animation() : Sprite(0, 0){
	}
	virtual ~Animation() {

	}
	int GetWidth() {
		return frames[index].w;
	}
	int GetHeight() {
		return frames[index].h;
	}
	unsigned int PixelAt(int x, int y) {
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
	char GetData(int x, int y) {
		if (!HFLIPPED) {
			return frames[index].data[x][y];
		}
		else {
			return frames[index].data[width-x-1][y];
		}
	}
	void Advance(int t) {
		if (t%interval==0) {
			index++;
			if (index>=numFrames) index=0;
		}
	}
	int interval = 1;
	int index = 0;
	Frame* frames;

	int numFrames = 0;

};

#endif /* ANIMATION_H_ */
