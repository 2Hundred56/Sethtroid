/*
 * Player.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "Player.h"
#include <cmath>
Player::Player(Game* game) : PhysicsObject(game) {

}

void Player::LoadResources() {
	//MAKE SURE YOU INITIALIZE YOUR TRIGGER FIRST!
	//0 = Right, 1 = Up, 2 = Left, 3 = Down
	Rect r = trigger->shape->ContainBox(Vector(0, 0));
	float hw = r.w/2;
	float hh = r.h/2;
	float off = 2;
	solidTriggers.push_back(new OffsetTrigger(new CollisionInfo(), new AABB(0.5, hh-off), FOOT, this, Vector(hw+0.5, 0), RIGHT_ONLY));
	solidTriggers.push_back(new OffsetTrigger(new CollisionInfo(), new AABB(hw-off, 0.5), FOOT, this, Vector(0, -hh-0.5), UP_ONLY));
	solidTriggers.push_back(new OffsetTrigger(new CollisionInfo(), new AABB(0.5, hh-off), FOOT, this, Vector(-hw-0.5, 0), LEFT_ONLY));
	solidTriggers.push_back(new OffsetTrigger(new CollisionInfo(), new AABB(hw-off, 0.5), FOOT, this, Vector(0, hh+0.5), DOWN_ONLY));
	velocity=Vector(6, -6);
}


void Player::GeneralUpdate() {
	grounded = solidTriggers[3]->cstorage.y<=-1;
	PhysicsObject::GeneralUpdate();
	//ChooseState();
	//ExecuteState();
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::ChooseState() {
	State choice = STANDING;
	int direction = sign(game->interface->horizInput);
	if (grounded) {
		velocity.y=0;
		if (game->interface->justJumping) {
			velocity.y=-JumpVelocity();
		}
		if (direction==0) choice = STANDING;
		else {
			if (gsp==0 || direction==sign(gsp)) choice = RUNNING;
			else choice = BRAKING;
		}
	}
	else {
		if (velocity.y<0) choice = JUMPING;
		else choice = FALLING;
	}
	ChangeState(choice);
}

void Player::ExecuteState() {
	if (state==STANDING) {
		if (gsp!=0) {
			if (std::abs(gsp)<Friction()) gsp = 0;
			else gsp -= sign(gsp)*Friction();
		}
	}
	else if (state==RUNNING) {
		if (std::abs(gsp)<TopSpeed()) gsp += sign(gsp)*Accel();
	}
	else if (state==BRAKING) gsp -= sign(gsp)*Decel();
	else if (state==JUMPING || state==FALLING) {
		if (velocity.y<TerminalVel()) velocity=velocity+Gravity();
		if (facing!=0 && facing==sign(gsp)) {
			gsp+=sign(gsp)*AirAccel();
		}
		else if (facing!=sign(gsp) && gsp!=0) {
			gsp-=sign(gsp)*AirDecel();
		}
	}
}

void Player::ExitState(State oldState) {
	//This function intentionally left blank
}

void Player::EnterState(State newState) {
	switch (newState) {
	case STANDING:
		current=standing;
		break;
	case RUNNING:
		current=running;
		break;
	case BRAKING:
		current=braking;
		break;
	case JUMPING:
		current=jumping;
		break;
	case FALLING:
		current=falling;
		break;
	}
	current->index=0;
}

void Player::ChangeState(State newState) {
	if (state==newState) return;
	ExitState(state);
	EnterState(newState);
	state=newState;
}
