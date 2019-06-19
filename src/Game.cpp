/*
 * Game.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#include "Game.h"
#include "SDLInterface.h"
#include "GameObject.h"
#include "Tileset.h"
#include "CollisionManager.h"
#include "RenderingTerms.h"
#include "Animation.h"
#include "TileLayer.h"
#include <iostream>
Game::Game() {
	// TODO Auto-generated constructor stub
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

Animation* Game::GetAnimation(char* key) {
	return interface->GetAnimation(key);
}

bool Game::Initialize() {
	clock=0;
	screenWidth = 640;
	screenResolution=4.0/3.0;
	interface = new SDLInterface(this, screenWidth, screenResolution);
	interface->InitGraphics();
	manager = new CollisionManager(this, 0);
	LoadResources();
	LoadLevel("levels/testlevel.bin", 0, 0);
}

void Game::Destroy(GameObject* obj) {
	if (obj->RespawnsOnDeath()) {
		obj->Reset();
		obj->SetSpawnStatus(0);
	}
	else {
		objects.erase(objects.find(obj), objects.end());
	}

}

void Game::AddObject(GameObject* obj) {
	objects.insert(obj);
}

void Game::Close() {
	interface->CloseGraphics();
}

void Game::RenderTile(TileLayer* layer, Tileset* set, int tile, Vector pos) {
	for (int i = pos.x; i<pos.x+layer->TileSize(); i++) {
		for (int j = pos.y; j<pos.y+layer->TileSize(); j++) {
			interface->WritePixel(i, j, set->TilePixelAt(tile, i, j));
		}
	}
}

void Game::RenderAnimation(Animation* anim, Vector pos, int index, RenderData data) {
	Vector animSize=Vector(anim->GetWidthI(index), anim->GetHeightI(index));
	for (int i=0; i<animSize.x; i++) {
		for (int j=0; j<animSize.y; j++) {
			interface->WritePixel(anim->PixelAtI(index, i, j), i+pos.x-camera.x, j+pos.y-camera.y);
		}
	}
}


std::forward_list<Collision> Game::GetCollisions(CollisionTrigger* trigger,
		int flag) {
	return manager->GetCollisions(trigger, flag);
}

void Game::AddLayer(Layer* layer) {
	layers.push_front(layer);
}

bool Game::Update() {
	input=interface->EventPoll();
	if (input.quit) return false;
	int flag;
	//TODO: Update camera
	if (clock>500) {
		cameraZoom*=1.005;
	}
	camera=Rect(20, 20, int(60*cameraZoom), int(60*cameraZoom)/screenResolution);
	spawnZone = Rect(camera.x-spawnZoneOffset, camera.y-spawnZoneOffset, camera.w+spawnZoneOffset*2, camera.h+spawnZoneOffset*2);
	despawnZone = Rect(camera.x-despawnZoneOffset, camera.y-despawnZoneOffset, camera.w+despawnZoneOffset*2, camera.h+despawnZoneOffset*2);
	for (auto it = objects.begin(); it!=objects.end(); it++) {

		flag = (*it) -> GetSpawnStatus();

		if (flag==0) {
			if (RectOverlap((*it)->LoadingRect(), spawnZone)) {
				(*it)->SetSpawnStatus(1);
				(*it)->Initialize();
				(*it)->InitialUpdate();
			}
		}
		else if (flag==1) {
			(*it)->InitialUpdate();
			if (RectOverlap((*it)->LoadingRect(), despawnZone)) {
				if (!RectOverlap((*it)->LoadingRect(), spawnZone)) {
					(*it)->SetSpawnStatus(2);
				}
			}
			else {
				(*it)->SetSpawnStatus(0);
				(*it)->Reset();
			}
		}
		else if (flag==2) {
			if (!RectOverlap((*it)->LoadingRect(), despawnZone)) {
				(*it)->SetSpawnStatus(0);
				(*it)->Reset();
			}
			else if (RectOverlap((*it)->LoadingRect(), spawnZone)) {
				(*it)->SetSpawnStatus(1);
			}
		}

	}
	interface->BeginGraphics();
	manager->UpdateGrid();
	for (auto it = objects.begin(); it!=objects.end(); it++) if ((*it)->GetSpawnStatus()==1) (*it)->CollisionPoll();
	for (auto it = objects.begin(); it!=objects.end(); it++) if ((*it)->GetSpawnStatus()==1) (*it)->GeneralUpdate();
	for (auto it = layers.begin(); it!=layers.end(); it++) (*it)->Render();
	for (auto it = objects.begin(); it!=objects.end(); it++) if ((*it)->GetSpawnStatus()==1) (*it)->Render();
	interface->UpdateGraphics();
	for (auto it = objects.begin(); it!=objects.end(); it++) if ((*it)->GetSpawnStatus()==1) (*it)->LateUpdate();
	clock++;
	return true;
}
