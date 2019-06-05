/*
 * CollisionManager.cpp
 *
 *  Created on: Jun 3, 2019
 *      Author: triforce
 */

#include "CollisionManager.h"
#include <set>
#include <cmath>
using CollisionTile = std::forward_list<CollisionTrigger*>;
CollisionManager::CollisionManager(int w, int h) {
	tileGrid = new CollisionTile*[w];
	width=w;
	height=h;
	for (int i=0; i<width; i++) {
		tileGrid[i]=new CollisionTile[h];
	}
	nextID=0;
}

CollisionManager::~CollisionManager() {
}

void CollisionManager::AddTrigger(CollisionTrigger* trigger) {
	trigger->id=nextID;
	nextID++;
	triggers.push_front(trigger);
}

int sign(float f) {
	if (f<0) return -1;
	else return 1;
}

void CollisionManager::UpdateGrid() {
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			tileGrid[i][j].clear();
		}
	}
	CollisionTrigger* trigger;
	for (auto it=triggers.begin(); it!=triggers.end(); it++) {
		trigger = *it;
		if (trigger->flag&tilingFlag) {
			tileGrid[(int) trigger->pos.x/tileSize][(int) trigger->pos.y/tileSize].push_front(trigger);
		}
	}
}

Vector CollisionManager::CheckCollision(Shape* s1, Vector p1, Shape* s2, Vector p2) {
	std::set<Vector> axes = s1->Axes(p2-p1);
	std::set<Vector> axes2 = s2->Axes(p1-p2);
	auto it = axes2.begin();
	float ca, axisLength, sgn, offset;
	Vector axis = Vector(0, 0);
	Vector maxAxis = Vector(0, 0);
	float minDst=1000;
	for (it=axes2.begin(); it!=axes2.end(); it++) {
		axes.insert(*it);
	}
	for (it=axes.begin(); it!=axes.end(); it++) {
		axis=*it;
		Vector proj1 = s1->Proj(axis)+Vector(proj(p1, axis),proj(p1, axis));
		Vector proj2 = s2->Proj(axis)+Vector(proj(p2, axis),proj(p2, axis));
		axisLength=std::abs(proj1.x-proj2.x+proj1.y-proj2.y)/2;
		ca = (proj1.y-proj1.x+proj2.y-proj2.x)/2;
		if (axisLength>ca) return Vector(0, 0);
		sgn=sign(proj1.x-proj2.x+proj1.y-proj2.y);
		offset=std::abs(axisLength-ca);
		if (offset<minDst) {
			minDst=offset*sgn;
			maxAxis=axis;
		}
	}
	return maxAxis*minDst;
}

std::forward_list<Collision> CollisionManager::GetCollisions(
		CollisionTrigger* trigger, int flag) {
	std::forward_list<Collision> collisions;
	TileLayer* layer;
	Tile* tile;
	Vector v;
	Rect r = trigger->shape->ContainBox(trigger->pos);
	int i1, i2, j1, j2, i, j;
	for (auto it=tileLayers.begin(); it!=tileLayers.end(); it++) {
		layer=*it;
		i1 = (r.x)/(layer->tileSize);
		i2 = (r.x+r.w)/(layer->tileSize);
		j1 = (r.y)/(layer->tileSize);
		j2 = (r.y+r.h)/(layer->tileSize);
		i = i1;
		j = j1;
		while (true) {
			tile=layer->getTile(i, j);
			if (tile->flag&flag) {
				v=CheckCollision(trigger->shape, trigger->pos, tile->shape, Vector((i+0.5)*layer->tileSize,(j+0.5)*layer->tileSize));
				if (v.x!=0 || v.y!=0) {
					collisions.push_front(Collision(tile->info, v, Vector((i+0.5)*layer->tileSize,(j+0.5)*layer->tileSize), tile->flag));
				}
			}
			i++;
			if (i>i2) {
				i=i1;
				j++;
			}
			if (j>j2) break;
		}
	}
	for (i=(int) trigger->pos.x/tileSize-1; i<(int) trigger->pos.x/tileSize+1; i++) {
		for (j=(int) trigger->pos.y/tileSize-1; j<(int) trigger->pos.y/tileSize+1; j++) {
			CollisionTile tile = tileGrid[i][j];
			for (auto it=tile.begin(); it!=tile.end(); it++) {
				CollisionTrigger* other = *it;
				v=CheckCollision(trigger->shape, trigger->pos, other->shape, other->pos);
				if (v.x!=0 || v.y!=0) {
					collisions.push_front(Collision(other->info, v, other->pos, other->flag));
				}
			}
		}
	}
	return collisions;
}
