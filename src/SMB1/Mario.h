/*
 * Mario.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef SMB1_MARIO_H_
#define SMB1_MARIO_H_
#include <cmath>
#include "../Player.h"
#include <iostream>
#include "../Game.h"
namespace smb1 {
class Mario: public Player {
public:
	Mario(Game* game, PlayerData data) : Player(game, data), GameObject(game, data) {

	}
	CollisionTrigger* GetTrigger() {
		return trigger;
	}
	bool IsRunning() {return game->InputB(playerNo, which);}
	bool IsJumping() {return game->InputA(playerNo, which);}
	void GeneralUpdate() {
		Player::GeneralUpdate();
		if (grounded) bounced = false;
	}
	void LoadResources() {
		trigger=new OffsetTrigger(new ObjectInfo(this), new AABB(8, 8), HIT|FOOT, this, Vector(0, 0));
		stateAnimations[RUNNING] = game->GetAnimation("SMB1-Mario-Run");
		stateAnimations[BRAKING] = game->GetAnimation("SMB1-Mario-Brake");
		stateAnimations[STANDING] = game->GetAnimation("SMB1-Mario-Idle");
		stateAnimations[JUMPING] = game->GetAnimation("SMB1-Mario-Jump");
		stateAnimations[FALLING] = game->GetAnimation("SMB1-Mario-Jump");
		Player::LoadResources();
	}
	Vector Gravity() {
		return Vector(0,0);
		if (IsJumping() && (velocity.y>0) && !bounced) {
			if (std::abs(gsp)<1) return Vector(0, 0.125);
			if (std::abs(gsp)<2.5) return Vector(0, 0.1171875);
			else return Vector(0, 0.15625);
		}
		else {
			if (std::abs(gsp)<1) return Vector(0, 0.4375);
			if (std::abs(gsp)<2.5) return Vector(0, 0.375);
			else return Vector(0, 0.5625);
		}
	}
	float Friction() {
		return 0.046875;
	}
	float TerminalVel() {
		return 4.5;
	}
	float Accel() {
		if (IsRunning()) {
			return 0.054745;
		}
		else {
			return 0.035278;
		}
	}
	float MinWalk() {
		return 1.1875;
	}
	float Decel() {
		return 0.101563;
	}
	float JumpVelocity() {
		if (std::abs(gsp)<1) return 4;
		if (std::abs(gsp)<2.5) return 4;
		else return 5;
	}
	float TopSpeed() {
		if (IsRunning()) return 2.5625;
		else return 1.5625;
	}
	float AirAccel() {
		if (IsRunning() ) return 0.0508422;
		else return 0.0352783;
	}
	float AirDecel() {
		if (IsRunning()) return 0.0508422;
		else return 0.0352783;
	}
	void ReceiveDamage(float dmg, Vector axis, DamageType type, GameObject* source) {
		if (axis.y>0) {
			if (source!=0) source->ReceiveDamage(3, -axis, BLUNT, this);
			bounced=true;
			velocity.y=-4;
		}
		else {
			Player::ReceiveDamage(dmg, axis, type, source);
		}
	}
protected:
	bool bounced=false;
	CollisionTrigger* trigger;
};
}



#endif /* SMB1_MARIO_H_ */
