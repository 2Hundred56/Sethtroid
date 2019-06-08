/*
 * Player.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "Player.h"

Player::Player(Game* game) : PhysicsObject(game) {

}

void Player::GeneralUpdate(){
	PhysicsObject::GeneralUpdate();
	current->Advance(game->clock);
	grounded=(displacement.y<0);
	if (!grounded) {

		if (velocity.y>-TerminalVel()) {
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
			if (grounded) {
				gsp-=Decel();
				ChangeState(BRAKING);
			}
			else gsp-=AirDecel();

		}
		else if (gsp>-TopSpeed()) {
			if (grounded) {
				gsp-=Accel();
				ChangeState(RUNNING);
			}
			else gsp-=AirAccel();

		}
		else {
			gsp+=Friction();
		}
	}
	else if (game->interface->horizInput>0) {
		current->HFLIPPED=false;
		if (gsp<0) {
			if (grounded) {
				gsp+=Decel();
				ChangeState(BRAKING);
			}
			else gsp+=AirDecel();
		}
		else if (gsp<TopSpeed()) {
			if (grounded) {
				gsp+=Accel();
				ChangeState(RUNNING);
			}
			else gsp+=AirAccel();

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
	if (grounded && game->interface->justJumping) {
		velocity.y=-JumpVelocity();
	}
	velocity.x=gsp;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

