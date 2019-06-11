/*
 * Player.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "PhysicsObject.h"
#include "Animation.h"

enum State {
	STANDING, RUNNING, BRAKING, JUMPING, FALLING
};

class Player: public PhysicsObject {
public:
	Player(Game* game);
	virtual void LoadResources();
	virtual void GeneralUpdate();
	virtual ~Player();
	bool grounded=false;
	virtual Vector Gravity() = 0;
	virtual float Accel() = 0;
	virtual float Decel() = 0;
	virtual float TopSpeed() = 0;
	virtual float AirAccel() = 0;
	virtual float AirDecel() = 0;
	virtual float Friction() = 0;
	virtual float JumpVelocity() = 0;
	virtual void ChooseState();
	virtual void ExecuteState();
	virtual void EnterState(State);
	virtual void ExitState(State);
	virtual void Render() {
		Vector choice = pos-Vector(current->GetWidth()/2.0, current->GetHeight()/2.0);
		game->interface->BlitSprite(current, (int) choice.x, (int) choice.y);
		for (auto it = solidTriggers.begin(); it!=solidTriggers.end(); it++) {
			game->interface->MassWrite(255<<16+255, (*it)->shape->ContainBox((*it)->GetPos()));
		}
	}
	virtual float TerminalVel() = 0;
	void ChangeState(State newState);
	float gsp = 0;
protected:
	Animation* standing = NULL;
	Animation* running = NULL;
	Animation* braking = NULL;
	Animation* jumping = NULL;
	Animation* falling = NULL;
	Animation* current = NULL;
	CollisionTrigger* trigger;
	State state = STANDING;
};

#endif /* PLAYER_H_ */
