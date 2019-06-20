/*
 * Player.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */
#include "Player.h"
#include "Game.h"
#include "RenderingTerms.h"
#include "Animation.h"

void Player::Initialize() {
	gsp=0;
	facing=1;
	direction=1;
	state = STANDING;
	//MAKE SURE YOU INITIALIZE YOUR TRIGGER FIRST!
	Rect r = GetTrigger()->shape->ContainBox();
	float hw = r.w/2;
	float hh = r.h/2;
	float off = 3;
	solidTriggers.push_back(new OffsetTrigger(new ObjectInfo(this), new AABB(0.5, hh-off*2), FOOT, this, Vector(hw+0.5, 0), RIGHT_ONLY));
	solidTriggers.push_back(new OffsetTrigger(new ObjectInfo(this), new AABB(hw-off, 0.5), FOOT, this, Vector(0, -hh-0.5), UP_ONLY));
	solidTriggers.push_back(new OffsetTrigger(new ObjectInfo(this), new AABB(0.5, hh-off*2), FOOT, this, Vector(-hw-0.5, 0), LEFT_ONLY));
	solidTriggers.push_back(new OffsetTrigger(new ObjectInfo(this), new AABB(hw-off, 0.5), FOOT, this, Vector(0, hh+0.5), DOWN_ONLY));
}

Player::Player(Game* game, PlayerData data) : LivingObject(game, data){
	playerNo=data.playerNo;
}


void Player::GeneralUpdate() {
	if (invFrames>0) invFrames--;
	if (game->InputX(playerNo, which)!=0) {
		facing = game->InputX(playerNo, which);
	}
	if (facing==-1) {
		renderData=RenderData(XFLIP);
	}
	else {
		renderData=RenderData(NONE);
	}
	LivingObject::GeneralUpdate();
	if (sign(displacement.x)==-sign(gsp)) gsp=0;
	if (sign(displacement.y)==-sign(velocity.y)) velocity.y=0;
	velocity.x=gsp;
}

void Player::ChooseState() {
	State choice = STANDING;
	if (grounded) {
		velocity.y=0;
		if (game->InputA(playerNo, which)) {
			velocity.y= - JumpVelocity();
			choice = JUMPING;
		}
		if (game->InputX(playerNo, which)==0) choice = STANDING;
		else {
			if (gsp==0 || game->InputX(playerNo, which)==sign(gsp)) choice = RUNNING;
			else choice = BRAKING;
		}
	}
	else {
		if (velocity.y<0) choice = JUMPING;
		else choice = FALLING;
	}
	ChangeState(choice);
}

void Player::ReceiveDamage(float dmg, Vector axis, DamageType type,
		GameObject* source) {
	if (invFrames>0) return;
	else {
		invFrames=InvincibleLength();
		LivingObject::ReceiveDamage(dmg, axis, type, source);
	}
}

void Player::ExecuteState() {
	if (state==STANDING) {
		if (gsp!=0) {
			if (std::abs(gsp)<Friction()) gsp = 0;
			else gsp -= sign(gsp)*Friction();
		}
	}
	else if (state==RUNNING) {
		if (gsp==0) {
			gsp=game->InputX(playerNo, which)*MinWalk();
		}
		else {
			if (std::abs(gsp)<TopSpeed()) gsp += game->InputX(playerNo, which)*Accel();
		}
	}
	else if (state==BRAKING) gsp += game->InputX(playerNo, which)*Decel();
	else if (state==JUMPING || state==FALLING) {
		if (game->InputX(playerNo, which)!=0 && (game->InputX(playerNo, which)==sign(gsp)|gsp==0) && std::abs(gsp)<TopSpeed()) {
			gsp+=game->InputX(playerNo, which)*AirAccel();
		}
		else if (game->InputX(playerNo, which)!=sign(gsp) && gsp!=0) {
			gsp+=game->InputX(playerNo, which)*AirDecel();
		}
	}
	LivingObject::ExecuteState();
}


Player::~Player() {
}

void Player::Death() {
	ChangeState(DYING);
}
