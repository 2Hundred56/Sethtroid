/*
 * PhysicsObject.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "PhysicsObject.h"
#include <cmath>

PhysicsObject::PhysicsObject(Game* game): GameObject(game){
	trigger=0;
	displacement = Vector(0, 0);
}

PhysicsObject::~PhysicsObject() {
	// TODO Auto-generated destructor stub
}

void PhysicsObject::InitialUpdate() {
	pos+=velocity;
	trigger->pos = pos;
}

void PhysicsObject::CollisionPoll() {
	displacement = Vector(0, 0);
	std::forward_list<Collision> collisions = game->manager->GetCollisions(trigger, SOLID);
	for (auto it = collisions.begin(); it!=collisions.end(); it++) {
		if (std::abs((*it).normal.x)>std::abs(displacement.x)) {
			displacement.x=(*it).normal.x;
		}
		if (std::abs((*it).normal.y)>std::abs(displacement.y)) {
			displacement.y=(*it).normal.y;
		}
	}
}

void PhysicsObject::GeneralUpdate() {
	pos+=displacement-Vector(sign(displacement.x), sign(displacement.y));
	if (displacement.y>0 && velocity.y<0) {
		velocity.y=0;
	}
}
