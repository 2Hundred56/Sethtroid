/*
 * CollisionManager.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef COLLISIONMANAGER_H_
#define COLLISIONMANAGER_H_
#include "Physics.h"
#include <forward_list>
#include <vector>
class Game;
class TileLayer;
class CollisionManager {
public:
	CollisionManager(Game* game, TileLayer* layer = 0);
	virtual ~CollisionManager();
	void AddTrigger(CollisionTrigger* trigger);
	void RemoveTrigger(CollisionTrigger* trigger);
	void UpdateGrid();
	void Reset();
	Vector CheckCollision(Shape*, Vector, Shape*, Vector, int cflag);
	std::forward_list<Collision> GetCollisions(CollisionTrigger* trigger, int flag);
protected:
	Game* game;
	TileLayer* layer;
	std::vector<CollisionTrigger*> triggers;
	std::forward_list<CollisionTrigger*>** tileGrid;
	int tileSize = 32;
	int width = 0;
	int height = 0;
	int tilingFlag = SOLID | HIT | HIT2;
};

#endif /* COLLISIONMANAGER_H_ */
