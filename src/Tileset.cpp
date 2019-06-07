#include "Tileset.h"

Tileset::Tileset(int w, int h) : Sprite(w, h) {
	tiles = new Tile*[16];
}

Tileset::~Tileset() {
}

unsigned int Tileset::TilePixelAt(int tile, int x, int y) {
	return PixelAt(tiles[tile]->originX+x, tiles[tile]->originY+y);
}

