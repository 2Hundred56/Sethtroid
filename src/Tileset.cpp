/*
 * Tileset.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: triforce
 */
#include "Tileset.h"
#include "Tile.h"

Tileset::Tileset(int w, int h) {
	width=w;
	height=h;

}

Tileset::~Tileset() {
}

unsigned int Tileset::TilePixelAt(int tile, int x, int y) {
	return palettes[data[(tiles[tile]->originX + x)][tiles[tile]->originY + y]];
}



