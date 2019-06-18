/*
 * PhysicsObject.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */
#include "PhysicsObject.h"
#include "Game.h"

PhysicsObject::PhysicsObject(Game* game, LoadingData data) : GameObject(game, data){

}

PhysicsObject::~PhysicsObject() {

}

void PhysicsObject::InitialUpdate() {
	pos+=velocity;
}

void PhysicsObject::GeneralUpdate() {
	pos+=displacement-Vector(sign(displacement.x), sign(displacement.y));
}

void PhysicsObject::Initialize() {
	velocity = Vector(0, 0);
	displacement = Vector(0, 0);
}

void PhysicsObject::CollisionPoll() {
	displacement=Vector(0, 0);
	std::forward_list<Collision> collisions;
	std::vector<OffsetTrigger*> striggers = SolidTriggers();
	for (auto it = striggers.begin(); it!=striggers.end(); it++) {
		collisions=game->GetCollisions((*it), solidFlag);
		for (auto it2 = collisions.begin(); it2!=collisions.end(); it2++) {
			if (((*it2).normal.y)<0 && (*it)->GetPos().y>(*it2).otherPos.y) continue;
			if (((*it2).normal.y)>0 && (*it)->GetPos().y<(*it2).otherPos.y) continue;
			if (std::abs((*it2).normal.x)>std::abs(displacement.x)) displacement.x = (*it2).normal.x;
			if (std::abs((*it2).normal.y)>std::abs(displacement.y)) displacement.y = (*it2).normal.y;
		}
	}
}
