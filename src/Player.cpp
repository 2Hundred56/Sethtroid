/*
 * Player.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "Player.h"

Player::Player() : PhysicsObject(), SpritedObject() {

}

void Player::GeneralUpdate() {
	grounded=(displacement.y<0);
	if (!grounded) {
		velocity+=Gravity();
		if (velocity.y>0) ChangeState(JUMPING);
		else ChangeState(FALLING);
	}
	else {
		velocity.y=0;
	}
	if (game->interface->horizInput<0) {
		current->HFLIPPED=true;
		if (gsp>0) {
			if (grounded) gsp-=Decel();
			else gsp-=AirDecel();
			ChangeState(BRAKING);
		}
		else if (gsp>-TopSpeed()) {
			if (grounded) gsp-=Accel();
			else gsp-=AirAccel();
			ChangeState(RUNNING);
		}
	}
	else if (game->interface->horizInput>0) {
		current->HFLIPPED=false;
		if (gsp<0) {
			if (grounded) gsp+=Decel();
			else gsp+=AirDecel();
			ChangeState(BRAKING);
		}
		else if (gsp<TopSpeed()) {
			if (grounded) gsp+=Accel();
			else gsp+=AirAccel();
			ChangeState(RUNNING);
		}
	}
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

