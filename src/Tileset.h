/*
 * Tileset.h
 *
 *  Created on: Jun 1, 2019
 *      Author: triforce
 */

#ifndef TILESET_H_
#define TILESET_H_
#include "Tile.h"
#include "Sprite.h"
class Tileset : public Sprite{
public:
	Tileset();
	virtual ~Tileset();
	unsigned int TilePixelAt(int tile, int x, int y);
	Tile* GetTile(int i) const { return tiles[i]; }
protected:
	Tile** tiles;
};

#endif /* TILESET_H_ */
