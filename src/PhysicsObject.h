/*
 * PhysicsObject.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef PHYSICSOBJECT_H_
#define PHYSICSOBJECT_H_

#include "GameObject.h"
#include "Physics.h"

class PhysicsObject: public virtual GameObject {
public:
	PhysicsObject(Game* game);
	virtual ~PhysicsObject();
	virtual void InitialUpdate();
	virtual void CollisionPoll();
	virtual void GeneralUpdate();
protected:
	CollisionTrigger* trigger;
	Vector velocity;
	Vector displacement;
};

#endif /* PHYSICSOBJECT_H_ */
