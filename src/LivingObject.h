/*
 * LivingObject.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef LIVINGOBJECT_H_
#define LIVINGOBJECT_H_
enum State {
	STANDING, RUNNING, BRAKING, JUMPING, FALLING, DYING
};
class Animation;
#include "PhysicsObject.h"
#include "RenderingTerms.h"
#include <map>
class LivingObject : public PhysicsObject{
public:
	LivingObject(Game* game, LoadingData data);
	virtual ~LivingObject();
	virtual void GeneralUpdate();
	virtual void Initialize();
	virtual void Reset();
	virtual std::vector<OffsetTrigger*> SolidTriggers();
	virtual CollisionTrigger* GetTrigger() = 0;
	virtual Rect LoadingRect();
	virtual void ChooseState() = 0;
	virtual void ExecuteState();
	virtual void EnterState(State);
	virtual void ExitState(State);
	virtual void ChangeState(State newState);
	virtual float TerminalVel() = 0;
	virtual Vector Gravity() = 0;
	virtual void Death();
	virtual void Render();
	virtual void ReceiveDamage(float dmg, Vector axis, DamageType type, GameObject* source);
protected:
	std::vector<OffsetTrigger*> solidTriggers;
	Vector gravity;
	bool grounded;
	int frameIndex;
	float hp;
	State state;
	std::map<State, Animation*> stateAnimations;
	Animation* current;
	RenderData renderData;
	bool ignoreCollisions = false;
};

#endif /* LIVINGOBJECT_H_ */
