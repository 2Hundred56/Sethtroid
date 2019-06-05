/*
 * Game.cpp
 *
 *  Created on: Jun 2, 2019
 *      Author: triforce
 */

#include "Game.h"
#include <chrono>
#include <iostream>
Game::Game() {

}

Game::~Game() {
}

int Game::Initialize() {
	t3 = new ThreeBy3(16);
	interface = new SDLInterface();
	interface->InitGraphics();
	sprite = interface->loadSprite("/Users/triforce/Desktop/supermariobros.bmp");
	t3->CopyData(sprite);

	layer=new TileLayer(50, 50, 16);
	layer->setTileset(1, t3);
	layer->setTile(10, 10, 1, 0);
	layer->setTile(11, 10, 1, 0);
	layer->setTile(12, 10, 1, 0);
	layer->setTile(13, 10, 1, 0);
	manager = new CollisionManager(16, 16);

	std::cout<<manager->CheckCollision(new AABB(16, 16), Vector(100, 100), new AABB(16, 16), Vector(116, 100));

	return 0;
}

bool Game::Update() {
	if (!interface->EventPoll()) return false;
//	manager->UpdateGrid();
	interface->BlitLayer(layer, 0, 0);
	interface->UpdateGraphics();
	return true;
}

void Game::Close() {
}
