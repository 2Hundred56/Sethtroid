/*
 * Sprite.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: triforce
 */

#include "Sprite.h"
#include <iostream>
Sprite::Sprite(int w, int h) {
	palettes = new unsigned int[16];
	data = new char*[w];
	for(int i = 0; i < w; ++i) data[i] = new char[h];
	width=w;
	height=h;
}

Sprite::~Sprite() {

}
unsigned int Sprite::PixelAt(int x, int y) {
	if (!HFLIPPED) {
		return palettes[data[x][y]];
	}
	else {
		return palettes[data[width-x-1][y]];
	}
}

void Sprite::FillBlack() {
	palettes[0] = 0x000000FF;
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			data[i][j]=0;
		}
	}
}

void Sprite::CopyData(Sprite* other) {
	palettes= other->palettes;
	int w = other->width;
	int h = other->height;
	data = new char*[w];
	for(int i = 0; i < w; ++i) data[i] = new char[h];
	for (int i=0; i<w; i++) {
		for (int j=0; j<h; j++) {
			data[i][j]=other->data[i][j];
		}
	}
	width=w;
	height=h;
}
