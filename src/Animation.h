/*
 * AnimationResource.h
 *
 *  Created on: Jun 6, 2019
 *      Author: triforce
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <vector>

struct Frame {
	char** data;
	int w;
	int h;
	Frame(char** d, int w, int h) : data(d), w(w), h(h) {

	}
};

class Animation {
public:
	Animation() {
		frames = std::vector<Frame>();
		palettes = new unsigned int [16];
	}
	virtual ~Animation() {

	}
	int GetWidthI(int index) {
		return frames[index].w;
	}
	int GetHeightI(int index) {
		return frames[index].h;
	}
	unsigned int PixelAtI(int index, int x, int y) {
		return palettes[frames[index].data[x][y]];
	}
	void AddFrame(char** data, int w, int h) {
		frames.push_back(Frame(data, w, h));
	}
	char GetDataI(int index, int x, int y) {
		return frames[index].data[x][y];
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
