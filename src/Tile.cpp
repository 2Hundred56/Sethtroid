#include "Tile.h"

Tile::Tile(int ox, int oy) {
	originX=ox;
	originY=oy;
}

Tile::Tile(int ox, int oy, float rs) {
	originX=ox;
	originY=oy;
	shape=new AABB(rs, rs);
}

Tile::~Tile() {
}
