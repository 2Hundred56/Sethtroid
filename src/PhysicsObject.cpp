/*
 * PhysicsObject.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "PhysicsObject.h"
#include <cmath>

PhysicsObject::PhysicsObject(Game* game) : GameObject(game){

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
	Collision collision;
	std::forward_list<Collision> collisions = game->manager->GetCollisions(trigger, SOLID);
	for (auto it = collisions.begin(); it!=collisions.end(); it++) {
		collision=*it;
		if (std::abs(collision.normal.x)>std::abs(displacement.x)) {
			displacement.x=collision.normal.x;
		}
		if (std::abs(collision.normal.y)>std::abs(displacement.y)) {
			displacement.y=collision.normal.y;
		}
	}
}

void PhysicsObject::GeneralUpdate() {
	pos+=displacement-Vector(sign(displacement.x), sign(displacement.y));
}
