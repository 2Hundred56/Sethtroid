/*
 * LivingObject.cpp
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#include "LivingObject.h"
#include "Animation.h"
#include "Game.h"

LivingObject::LivingObject(Game* game, LoadingData data) : PhysicsObject(game, data) {

}

LivingObject::~LivingObject() {
	// TODO Auto-generated destructor stub
}

void LivingObject::GeneralUpdate() {
	grounded = displacement.y<=-1;
	ChooseState();
	ExecuteState();
}

void LivingObject::Initialize() {
	grounded=false;
	frameIndex = 0;
	renderData = RenderData(NONE);
}

void LivingObject::Reset() {
	solidTriggers.clear();
}

std::vector<OffsetTrigger*> LivingObject::SolidTriggers() {
	return solidTriggers;
}

Rect LivingObject::LoadingRect() {
	return GetTrigger()->shape->ContainBox()+GetTrigger()->GetPos();
}

void LivingObject::EnterState(State newState) {
	auto it = stateAnimations.find(newState);
	if (it!=stateAnimations.end()) {
		current = it->second;
		frameIndex = 0;
	}
}

void LivingObject::ExitState(State enumState) {
	//This function intentionally left blank
}

void LivingObject::ChangeState(State newState) {
	if (state==newState) return;
	ExitState(state);
	EnterState(newState);
	state=newState;
}

void LivingObject::Render() {
	game->RenderAnimation(current, pos, frameIndex, renderData);
	if (game->GetClock()%current->interval==0) {
		frameIndex++;
		if (frameIndex>=current->NumFrames()) {
			frameIndex=0;
		}
	}
}

void LivingObject::ExecuteState() {
	if (!grounded) {
		velocity+=Gravity();
		if (velocity.y>TerminalVel()) velocity.y=TerminalVel();
	}
}

void LivingObject::Death() {
	game->Destroy(this);
}

void LivingObject::ReceiveDamage(float dmg, Vector axis, DamageType type,
		GameObject* source) {
	hp-=dmg;
	if (hp<=0) {
		Death();
	}
}
