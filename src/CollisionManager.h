/*
 * CollisionManager.h
 *
 *  Created on: Jun 3, 2019
 *      Author: triforce
 */

#ifndef COLLISIONMANAGER_H_
#define COLLISIONMANAGER_H_
#include "Physics.h"
#include "TileLayer.h"
#include <forward_list>
class CollisionManager {
public:
	CollisionManager(int, int);
	virtual ~CollisionManager();
	void AddTrigger(CollisionTrigger*);
	void UpdateGrid();
	Vector CheckCollision(Shape*, Vector, Shape*, Vector);
	std::forward_list<Collision> GetCollisions(CollisionTrigger*, int);
//protected:
	std::forward_list<CollisionTrigger*> triggers;
	void AddLayer(TileLayer* layer) {
		tileLayers.push_front(layer);
	}
protected:
	int nextID;
	int width, height;
	std::forward_list<CollisionTrigger*>** tileGrid;
	std::forward_list<TileLayer*> tileLayers;
	int tileSize = 32;
	int tilingFlag = SOLID;

};

#endif /* COLLISIONMANAGER_H_ */
