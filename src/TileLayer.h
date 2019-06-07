#ifndef TILE_LAYER_H_
#define TILE_LAYER_H_
#include "Tileset.h"
#include "Layer.h"
class TileLayer : public Layer {
public:
	TileLayer(int w, int h, int ts);
	virtual ~TileLayer();
	unsigned int PixelAt(int x, int y);
	void setTileset(int i, Tileset* tileset) { tilesets[i]=tileset; }
	void setTile(int i, int j, int tileset, int tile) { tilesetData[i][j]=tileset; tileData[i][j]=tile; }
	Tile* getTile(int i, int j) {
		if (tilesetData[i][j]!=0){
			return tilesets[tilesetData[i][j]]->GetTile(tileData[i][j]);
		}
		else {
			return 0;
		}
	}
	Tile* getTileWorld (float x, float y) {
		return getTile((int) (x/tileSize), (int) (y/tileSize));
	}
	int tileSize;
protected:
	Tileset** tilesets;
	char** tileData;
	char** tilesetData;
	int width, height;
};
#endif
