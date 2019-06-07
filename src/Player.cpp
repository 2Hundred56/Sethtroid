/*
 * Player.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "Player.h"

Player::Player(Game* game) : PhysicsObject(game) {

}

void Player::GeneralUpdate() {
	current->Advance(game->clock);
	grounded=true;//(displacement.y<0);
	if (!grounded) {

		if (velocity.y>-TerminalVel()) {
			std::cout<<velocity.y;
			velocity+=Gravity();
		}
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
		else {
			gsp+=Friction();
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
		else {
			gsp-=Friction();
		}
	}
	else if (grounded) {
		if (std::abs((int) gsp)>Friction()) gsp-=sign(gsp)*Friction();
		else gsp=0;
		if (gsp==0) {
			ChangeState(STANDING);
		}
	}
	velocity.x=gsp;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

