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
class OffsetTrigger : public CollisionTrigger {
public:
	OffsetTrigger(CollisionInfo* info, Shape* shape, int flag, GameObject* obj, Vector offset = Vector(0, 0), int cflag = 0): CollisionTrigger(info, shape, flag, cflag), offset(offset), obj(obj) {
	}
	Vector offset;
	Vector cstorage;
	GameObject* obj;
	const Vector GetPos() const { return obj->pos+offset;}
};
class PhysicsObject: public virtual GameObject {
public:
	PhysicsObject(Game* game);
	virtual ~PhysicsObject();
	virtual void InitialUpdate();
	virtual void CollisionPoll();
	virtual void GeneralUpdate();
protected:
	int facing = 1;
	Vector velocity;
	Vector displacement;
	std::vector<OffsetTrigger*> solidTriggers; //MAKE SURE YOU INITIALIZE THESE!
};

#endif /* PHYSICSOBJECT_H_ */
