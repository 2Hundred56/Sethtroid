#include "TileLayer.h"

TileLayer::TileLayer(int w, int h, int ts) {
	tilesets = new Tileset*[16];
	tileData = new char*[w];
	for(int i = 0; i < w; ++i) {
		tileData[i] = new char[h];
		for(int j = 0; j < h; ++j) {
			tileData[i][j]=0;
		}
	}
	tilesetData = new char*[w];
	for(int i = 0; i < w; ++i) {
		tilesetData[i] = new char[h];
		for(int j = 0; j < h; ++j) {
			tilesetData[i][j]=0;
		}
	}
	width=w;
	height=h;
	tileSize=ts;
}

TileLayer::~TileLayer() {
}

unsigned int TileLayer::PixelAt(int x, int y) {
	if (tilesetData[x/tileSize][y/tileSize]==0) return 0;
	return tilesets[tilesetData[x/tileSize][y/tileSize]]->TilePixelAt(tileData[x/tileSize][y/tileSize], x%tileSize, y%tileSize);
}
