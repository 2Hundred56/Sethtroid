/*
 * Tile.h
 *
 *  Created on: Jun 1, 2019
 *      Author: triforce
 */

#ifndef TILE_H_
#define TILE_H_
#include "Physics.h"
class Tile {
public:
	Tile(int, int);
	Tile(int, int, float);
	virtual ~Tile();
	int originX, originY;
	Shape* shape;
	CollisionInfo info;
	int flag;
};

#endif /* TILE_H_ */
