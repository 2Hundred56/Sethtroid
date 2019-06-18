/*
 * Tileset.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef TILESET_H_
#define TILESET_H_
#include "Sprite.h"
class Tile;
class Tileset {
public:
	Tileset(int, int);
	virtual ~Tileset();
	unsigned int TilePixelAt(int tile, int x, int y);
	Tile* GetTile(int i) const { return (tiles[i]); }
	Tile** tiles;
	int GetHeight() const { return height; }
	int GetWidth() const { return width; }
	int GetPalette(int i) const { return palettes[i]; }
	int NumPalettes() const {return numPalettes;}
	void SetPalette(int i, unsigned int pixel) { palettes[i]=pixel; if (numPalettes<(i+1)) numPalettes=i+1;}
	void SetPixel(int i, int j, char k) { data[i][j]=k; }
	char GetData(int i, int j) const {return data[i][j];}
	char CopyData(char** dat) { data=dat;}
/*	int GetTileSize() const {
		return tileSize;
	}

	void SetTileSize(int tileSize) {
		this->tileSize = tileSize;
	}*/

protected:
	char** data;
	int width, height;
	//int tileSize;
	unsigned int* palettes;
	int numPalettes = 0;
};

#endif /* TILESET_H_ */
