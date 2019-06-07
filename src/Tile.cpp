#include "Tile.h"

Tile::Tile(int ox, int oy, Shape* shape, int flag, CollisionInfo* info) : shape(shape), info(info), flag(flag) {
	originX=ox;
	originY=oy;
}

Tile::~Tile() {
}
