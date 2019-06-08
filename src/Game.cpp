/*
 * Game.cpp
 *
 *  Created on: Jun 2, 2019
 *      Author: triforce
 */

#include "Game.h"
#include <chrono>
#include <iostream>

#include "smb1/Mario.h"
#include "smb1/Goomba.h"
Game::Game() {
}

Game::~Game() {
}

int Game::Initialize() {
	clock=0;
	interface = new SDLInterface();
	interface->InitGraphics();
	std::forward_list<int> widths=std::forward_list<int>();
	widths.push_front(16);
	widths.push_front(16);
	interface->_WriteAnimation("rsrc/smb1/goomba.bin", interface->_ImportAnimation("/Users/triforce/Eclipse/Sethtroid/rsrc/smb1/goomba.bmp", widths, 3));
	manager = new CollisionManager(200,200);
	Tileset* set = interface->LoadTileset("rsrc/smb1/simple-tileset.bin");
	layers.push_back(new TileLayer(100, 100, 16));
	layers[0]->setTileset(1, set);
	layers[0]->setTile(6, 8, 1, 0);
	layers[0]->setTile(7, 8, 1, 0);
	layers[0]->setTile(8, 8, 1, 0);
	layers[0]->setTile(9, 8, 1, 0);
	layers[0]->setTile(10, 12, 1, 0);
	layers[0]->setTile(11, 12, 1, 0);
	layers[0]->setTile(12, 12, 1, 0);
	layers[0]->setTile(13, 12, 1, 0);
	layers[0]->setTile(14, 8, 1, 0);
	layers[0]->setTile(14, 7, 1, 0);
	for (int i=4; i<28; i++) {
		layers[0]->setTile(i, 12, 1, 0);
	}
	for (int i=14; i<20; i++) {
			layers[0]->setTile(i, 8, 1, 0);
		}
	layers[0]->setTile(20, 8, 1, 0);
	layers[0]->setTile(20, 7, 1, 0);
	manager->AddLayer(layers[0]);
	//TODO: Create objects
	gameObjects.push_front(new smb1::Goomba(this));
	gameObjects.front()->pos=Vector(240, 176);
	gameObjects.push_front(new smb1::Mario(this));
	gameObjects.front()->pos=Vector(100,100);
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) {
		(*it)->LoadResources();
	}
	return 0;
}

bool Game::Update() {
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->InitialUpdate();
	if (!interface->EventPoll()) return false;
	manager->UpdateGrid();
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->CollisionPoll();
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->GeneralUpdate();
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->LateUpdate();
	for (auto it=layers.begin(); it!=layers.end();it++) interface->BlitLayer((*it), 0, 0);
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->Render();
	interface->UpdateGraphics();
	clock++;
	return true;
}

void Game::Close() {
}
