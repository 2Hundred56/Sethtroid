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
	clock=0;
	interface = new SDLInterface();
	interface->InitGraphics();
	manager = new CollisionManager(200,200);
	//TODO: Create objects
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
