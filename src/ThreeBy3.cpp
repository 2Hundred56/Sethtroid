#include "ThreeBy3.h"

ThreeBy3::ThreeBy3(int imgSize) : Tileset() {
	for (int i=0; i<5; i++) {
		for (int j=0; j<3; j++) {
			tiles[5*j+i]=new Tile(i*imgSize, j*imgSize);
		}
	}
}

ThreeBy3::~ThreeBy3() {
}

