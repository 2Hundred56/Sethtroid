/*
 * PhysicsObject.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "PhysicsObject.h"
#include <cmath>

PhysicsObject::PhysicsObject(Game* game): GameObject(game){

}

PhysicsObject::~PhysicsObject() {
	// TODO Auto-generated destructor stub
}

void PhysicsObject::InitialUpdate() {
	pos+=velocity;
}

void PhysicsObject::CollisionPoll() {
	displacement=Vector(0, 0);
	Vector cstor;
	std::forward_list<Collision> collisions;
	for (auto it = solidTriggers.begin(); it!=solidTriggers.end(); it++) {
		cstor = Vector(0, 0);
		collisions=game->manager->GetCollisions((*it), SOLID);
		for (auto it2 = collisions.begin(); it2!=collisions.end(); it2++) {
			//game->paused=true;
			//std::cout<<(*it)->shape->ContainBox(Vector(0, 0))<<(*it)->GetPos()<<(*it2).normal<<(*it2).otherPos<<std::flush;
			//if ((displacement.x!=0 && sign(displacement.x)!=sign((*it2).normal.x)) || (displacement.y!=0 && sign(displacement.y)!=sign((*it2).normal.y))) throw('3');
			if (std::abs((*it2).normal.x)>std::abs(cstor.x)) cstor.x = (*it2).normal.x;
			if (std::abs((*it2).normal.y)>std::abs(cstor.y)) cstor.y = (*it2).normal.y;
			if (std::abs((*it2).normal.x)>std::abs(displacement.x)) displacement.x = (*it2).normal.x;
			if (std::abs((*it2).normal.y)>std::abs(displacement.y)) displacement.y = (*it2).normal.y;
		}
		//std::cout<<"Done"<<std::flush;
		(*it)->cstorage=cstor;
	}
	//std::cout<<"---\n"<<std::flush;
}
void PhysicsObject::GeneralUpdate() {
	pos+=displacement - Vector(sign(displacement.x), sign(displacement.y));
	if (displacement.x!=0) velocity.x*=-1;
	if (displacement.y!=0) velocity.y*=-1;
}
