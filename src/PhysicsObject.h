/*
 * PhysicsObject.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef PHYSICSOBJECT_H_
#define PHYSICSOBJECT_H_

#include <vector>

#include "GameObject.h"
#include "Physics.h"
class OffsetTrigger : public CollisionTrigger {
public:
	OffsetTrigger(CollisionInfo* info, Shape* shape, int flag, GameObject* obj, Vector offset = Vector(0, 0), int cflag = 0): CollisionTrigger(info, shape, flag, cflag), offset(offset), obj(obj) {
	}
	Vector offset;
	Vector cstorage;
	GameObject* obj;
	const Vector GetPos() const { return obj->GetPos()+offset;}
};
class PhysicsObject: public virtual GameObject {
public:
	PhysicsObject(Game* game, LoadingData data);
	virtual ~PhysicsObject();
	virtual void InitialUpdate();
	virtual void CollisionPoll();
	virtual void GeneralUpdate();
	virtual void Initialize();
	virtual std::vector<OffsetTrigger*> SolidTriggers() = 0;
protected:
	Vector velocity;
	Vector displacement;
	int solidFlag = SOLID;
};

#endif /* OLDSRC_PHYSICSOBJECT_H_ */
