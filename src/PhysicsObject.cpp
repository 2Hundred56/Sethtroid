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
	std::cout<<"==="<<"\n"<<std::flush;
	displacement = Vector(0, 0);
	std::forward_list<Collision> collisions = game->manager->GetCollisions(trigger, SOLID);
	for (auto it = collisions.begin(); it!=collisions.end(); it++) {

		if (std::abs((*it).normal.x)>=1 && std::abs((*it).normal.x)>std::abs(displacement.x)) {
			displacement.x=(*it).normal.x;
		}
		if (std::abs((*it).normal.y)>=1 && std::abs((*it).normal.y)>std::abs(displacement.y)) {
			displacement.y=(*it).normal.y;
		}
	}
	//if (displacement.x!=0) game->paused=true;
	//displacement=displacement-Vector(sign(displacement.x), sign(displacement.y))*2;
}

void PhysicsObject::GeneralUpdate() {
	pos+=displacement-Vector(sign(displacement.x), sign(displacement.y));
	if (sign(displacement.x)==sign(velocity.x)) velocity.x==0;
	if (displacement.y>0 && velocity.y<0) {
		velocity.y=0;
	}
}
