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
			tileGrid[(int) trigger->GetPos().x/tileSize][(int) trigger->GetPos().y/tileSize].push_front(trigger);
		}
	}
}

Vector CollisionManager::CheckCollision(Shape* s1, Vector p1, Shape* s2, Vector p2, int cflag) {
	//std::cout<<s1->ContainBox(p1)<<s2->ContainBox(Vector(p2))<<cflag<<":"<<std::flush;
	std::set<Vector> axes = s1->Axes(p2-p1);
	std::set<Vector> axes2 = s2->Axes(p1-p2);
	auto it = axes2.begin();
	float minDst = 1000;
	Vector maxAxis = Vector(0, 0);
	float diff, sep, maxSep, sgn;
	Vector axis = Vector(0, 0);
	for (it=axes2.begin(); it!=axes2.end(); it++) {
		axes.insert(*it);
	}
	for (it=axes.begin(); it!=axes.end(); it++) {
		axis=*it;
		Vector proj1 = s1->Proj(axis)+Vector(proj(p1, axis),proj(p1, axis));
		Vector proj2 = s2->Proj(axis)+Vector(proj(p2, axis),proj(p2, axis));
		maxSep = proj1.y-proj1.x+proj2.y-proj2.x; //maximum possible separation
		sep=std::max(proj1.y, proj2.y)-std::min(proj1.x, proj2.x);
		//std::cout<<"{"<<axis<<":"<<proj1<<";"<<proj2<<","<<sep<<"-"<<maxSep<<"}"<<std::flush;
		if (sep>=maxSep) return Vector(0, 0);
		sgn=sign(proj1.x-proj2.x+proj1.y-proj2.y);
		if (sgn<0) diff = (proj1.y-proj2.x);
		else diff=(proj2.y-proj1.x);
		//std::cout<<axis<<proj1<<"v"<<proj2<<":"<<std::flush;
		//We know we have a collision, now to test cflags before we go
		if (std::abs(axis.x)==1) { //We know it's normalized, so no need testing y coord
			//TODO: This code probably could be cleaned up
			if ((cflag&NO_LEFT) && (cflag&NO_RIGHT)) continue;
			if (((cflag&NO_LEFT) && sgn>0) || ((cflag&NO_RIGHT) && sgn<0)) continue;
		}
		else if (std::abs(axis.y)==1) { //Can you tell this was copied and pasted?
			if ((cflag&NO_UP) && (cflag&NO_DOWN)) continue;
			if (((cflag&NO_UP) && sgn>0) || ((cflag&NO_DOWN) && sgn<0)) continue;
		}
		else {
			if (cflag&NO_WEIRD) continue;
		}
		if ((diff*sgn)!=0 && diff<std::abs(minDst)) {
			minDst=diff*sgn;
			maxAxis=axis;
		}
	}
	//std::cout<<"/"<<maxAxis*minDst<<"\n"<<std::flush;
	return maxAxis*minDst;
}

std::forward_list<Collision> CollisionManager::GetCollisions(
		CollisionTrigger* trigger, int flag) {
	std::forward_list<Collision> collisions;
	TileLayer* layer;
	Tile* tile;
	Vector v;
	Rect r = trigger->shape->ContainBox(trigger->GetPos());
	int i1, i2, j1, j2, i, j;
	for (auto it=tileLayers.begin(); it!=tileLayers.end(); it++) {
		layer=*it;
		i1 = (int) (r.x)/(layer->tileSize);
		i2 = (int) (r.x+r.w)/(layer->tileSize);
		j1 = (int) (r.y)/(layer->tileSize);
		j2 = (int) (r.y+r.h)/(layer->tileSize);
		i = i1;
		j = j1;
		while (true) {
			tile=layer->getTile(i, j);
			if (tile!=0) {
				if (tile->flag&flag) {
					v=CheckCollision(trigger->shape, trigger->GetPos(), tile->shape, Vector((i+0.5)*layer->tileSize,(j+0.5)*layer->tileSize), (tile->cflag)|(trigger->cflag));
					if (v.x!=0 || v.y!=0) {
						collisions.push_front(Collision(tile->info, v, Vector((i+0.5)*layer->tileSize,(j+0.5)*layer->tileSize), tile->flag));
					}
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

	for (i=(int) trigger->GetPos().x/tileSize-1; i<(int) trigger->GetPos().x/tileSize+1; i++) {
		for (j=(int) trigger->GetPos().y/tileSize-1; j<(int) trigger->GetPos().y/tileSize+1; j++) {
			CollisionTile tile = tileGrid[i][j];

			for (auto it=tile.begin(); it!=tile.end(); it++) {
				CollisionTrigger* other = *it;

				v=CheckCollision(trigger->shape, trigger->GetPos(), other->shape, other->GetPos(), (trigger->cflag)|(other->cflag));
				if (v.x!=0 || v.y!=0) {
					collisions.push_front(Collision(other->info, v, other->GetPos(), other->flag));
				}
			}
		}
	}

	return collisions;
}
