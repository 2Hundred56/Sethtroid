/*
 * AnimationResource.h
 *
 *  Created on: Jun 6, 2019
 *      Author: triforce
 */

#ifndef ANIMATIONRESOURCE_H_
#define ANIMATIONRESOURCE_H_

#include "Sprite.h"
#include <vector>
struct Frame {
	char** data;
	int w;
	int h;
	Frame(char** d, int w, int h) : data(d), w(w), h(h) {

	}
};

class AnimationResource {
public:
	AnimationResource() {
		frames = std::vector<Frame>();
		palettes = new unsigned int [16];
	}
	virtual ~AnimationResource() {

	}
	int GetWidthI(int index) {
		return frames[index].w;
	}
	int GetHeightI(int index) {
		return frames[index].h;
	}
	unsigned int PixelAtI(int index, int x, int y, bool hflip) {
		if (!hflip) {
			return palettes[frames[index].data[x][y]];
		}
		else {
			return palettes[frames[index].data[GetWidthI(index)-x-1][y]];
		}
	}
	void AddFrame(char** data, int w, int h) {
		frames.push_back(Frame(data, w, h));
	}
	char GetDataI(int index, int x, int y, bool hflip) {
		if (!hflip) {
			return frames[index].data[x][y];
		}
		else {
			return frames[index].data[GetWidthI(index)-x-1][y];
		}
	}
	int NumFrames() {
		return frames.size();
	}
	int GetPalette(int i) const { return palettes[i]; }
	void SetPalette(int i, unsigned int pixel) { palettes[i]=pixel; if (numPalettes<(i+1)) numPalettes=i+1;}
	std::vector<Frame> frames;
	int interval = 1;
	unsigned int* palettes;
	int numPalettes = 0;

};

#endif
