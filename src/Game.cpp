/*
 * Game.cpp
 *
 *  Created on: Jun 2, 2019
 *      Author: triforce
 */

#include "Game.h"
#include "SMB1/Mario.h"
#include <chrono>
#include <iostream>
Game::Game() {
}

Game::~Game() {
}

int Game::Initialize() {
	std::cout<<"2";
	clock=0;
	interface = new SDLInterface();
	interface->InitGraphics();
	std::cout<<"3";
	manager = new CollisionManager(200,200);
	//TODO: Create objects
	gameObjects.push_front(new SMB1::Mario(this));
	gameObjects.front()->pos=Vector(100,100);
	std::cout<<"4";
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) {
		(*it)->LoadResources();
	}
	std::cout<<"5";
	return 0;
}

bool Game::Update() {
	std::cout<<"7";
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->InitialUpdate();
	std::cout<<"8";
	if (!interface->EventPoll()) return false;
	manager->UpdateGrid();
	std::cout<<"9";
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->CollisionPoll();
	std::cout<<"10";
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->GeneralUpdate();
	std::cout<<"11";
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->LateUpdate();
	std::cout<<"12";
	for (auto it = gameObjects.begin(); it!=gameObjects.end(); it++) (*it)->Render();
	std::cout<<"13";
	interface->UpdateGraphics();
	std::cout<<"14";
	clock++;
	return true;
}

void Game::Close() {
}
