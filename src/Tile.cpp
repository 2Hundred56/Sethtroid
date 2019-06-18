/*
 * Tile.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: triforce
 */

#include "Tile.h"

Tile::Tile(int ox, int oy, Shape* shape, int flag, CollisionInfo* info,
		int cflag) :
		shape(shape), info(info), flag(flag), cflag(cflag) {
	originX = ox;
	originY = oy;
}
