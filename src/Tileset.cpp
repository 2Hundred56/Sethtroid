/*
 * Tileset.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: triforce
 */
#include "Tileset.h"
#include "Tile.h"

Tileset::Tileset(int w, int h, int np) {
	width=w;
	height=h;
	palettes=new unsigned int[np];
	tiles = new Tile*[255];
	data = new char*[w];
	for(int i = 0; i < w; ++i) data[i] = new char[h];
}

Tileset::~Tileset() {
}

unsigned int Tileset::TilePixelAt(int tile, int x, int y) {
	return palettes[data[(tiles[tile]->originX + x)][tiles[tile]->originY + y]];
}



