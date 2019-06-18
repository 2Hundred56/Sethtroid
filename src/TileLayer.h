/*
 * TileLayer.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef TILELAYER_H_
#define TILELAYER_H_

#include "Layer.h"
class Tileset;
class Tile;

class TileLayer: public Layer {
public:
	TileLayer(Game* game, int w, int h, int tileSize);
	virtual ~TileLayer();
	void Render();
	void SetTileset(int i, Tileset* tileset);
	void SetTile(int i, int j, int tileset, int tile);
	Tile* GetTile(int i, int j);
	int GetTileNo(int i, int j);
	Tileset* GetTileset(int i, int j);
	int TileSize() const { return tileSize; }
protected:
	Tileset** tilesets;
	char** tileData;
	char** tilesetData;
	int width, height;
	int tileSize;
};

#endif /* TILELAYER_H_ */
