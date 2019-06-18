/*
 * TileLayer.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#include "TileLayer.h"
#include "Game.h"
#include "Tileset.h"
TileLayer::TileLayer(Game* game, int w, int h, int ts) : Layer(game) {
	width=w;
	height=h;
	tileSize=ts;
}

TileLayer::~TileLayer() {
	// TODO Auto-generated destructor stub
}

void TileLayer::Render() {
	for (int i = (int) (game->SpawnZone().x/tileSize); i<(int) ((game->SpawnZone().x+game->SpawnZone().w+1)/tileSize); i++) {
		for (int j = (int) (game->SpawnZone().y/tileSize); j<(int) ((game->SpawnZone().y+game->SpawnZone().h+1)/tileSize); j++) {
			game->RenderTile(this, GetTileset(i, j), GetTileNo(i, j), Vector(i, j));
		}
	}
}

void TileLayer::SetTileset(int i, Tileset* tileset) {
	tilesets[i]=tileset;
}

void TileLayer::SetTile(int i, int j, int tileset, int tile) {
	tilesetData[i][j]=tileset;
	tileData[i][j]=tileset;
}

Tile* TileLayer::GetTile(int i, int j) {
	return GetTileset(i, j)->GetTile(GetTileNo(i, j));
}

int TileLayer::GetTileNo(int i, int j) {
	return tileData[i][j];
}

Tileset* TileLayer::GetTileset(int i, int j) {
	return tilesets[tilesetData[i][j]];
}
