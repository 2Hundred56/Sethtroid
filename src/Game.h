/*
 * Game.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef GAME_H_
#define GAME_H_
#include <unordered_set>
#include "Physics.h"
#include "InputTerms.h"
class GameObject;
class CollisionManager;
class SDLInterface;
class Layer;
class TileLayer;
struct RenderData;
class Tileset;
class Animation;
#include <fstream>

class Game {
public:
	Game();
	~Game();
	bool Initialize();
	void LoadLevel(char* path, int chunk, int entranceData);
	GameObject* LoadObject(std::ifstream* input);
	Layer* LoadLayer(std::ifstream* input);
	bool Update();
	void Destroy(GameObject* obj);
	void AddObject(GameObject* obj);
	void AddLayer(Layer* layer);
	Animation* GetAnimation(char* key);
	void Close();
	float InputX(int playerNo, int which);
	float InputY(int playerNo, int which);
	float InputA(int playerNo, int which);
	float InputB(int playerNo, int which);
	float InputC(int playerNo, int which);
	float InputD(int playerNo, int which);
	float InputL(int playerNo, int which);
	float InputR(int playerNo, int which);
	void RenderAnimation(Animation* anim, Vector pos, int index, RenderData data);
	void RenderTile(TileLayer* layer, Tileset* set, int tile, Vector pos);
	void LoadResources();
	std::forward_list<Collision> GetCollisions(CollisionTrigger* trigger, int flag);

	const Rect DespawnZone() const {
		return despawnZone;
	}

	const Rect SpawnZone() const {
		return spawnZone;
	}

	const Rect Camera() const {
		return camera;
	}
	const int GetClock() const {
		return clock;
	}

protected:
	std::unordered_set<GameObject*> objects;
	std::forward_list<Layer*> layers;
	CollisionManager* manager;
	SDLInterface* interface;
	Rect camera;
	Rect spawnZone;
	Rect despawnZone;
	int clock;
	InputState input;
	int spawnZoneOffset;
	int despawnZoneOffset;
	int screenWidth;
	float screenResolution;
	Vector worldSize;
	float cameraZoom=1;
};

#endif /* GAME_H_ */
