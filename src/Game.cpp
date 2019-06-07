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
Game::Game() {
}

Game::~Game() {
}

int Game::Initialize() {
	clock=0;
	interface = new SDLInterface();
	interface->InitGraphics();
	manager = new CollisionManager(200,200);
	Tileset* set = interface->LoadTileset("rsrc/smb1/simple-tileset.bin");
	layer = new TileLayer(100, 100, 16);
	layer->setTileset(1, set);
	manager->AddLayer(layer);
	//TODO: Create objects
	gameObjects.push_front(new SMB1::Mario(this));
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
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->Render();
	interface->UpdateGraphics();
	clock++;
	return true;
}

void Game::Close() {
}
