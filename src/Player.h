/*
 * Player.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef OLDSRC_PLAYER_H_
#define OLDSRC_PLAYER_H_

#include "LivingObject.h"
#include <map>

class Player: public LivingObject {
public:
	Player(Game* game, PlayerData data);
	virtual void Initialize();
	virtual void GeneralUpdate();
	virtual ~Player();
	virtual float Accel() = 0;
	virtual float Decel() = 0;
	virtual float MinWalk() = 0;
	virtual float TopSpeed() = 0;
	virtual float AirAccel() = 0;
	virtual float AirDecel() = 0;
	virtual float InvincibleLength() = 0;
	virtual float Friction() = 0;
	virtual float JumpVelocity() = 0;
	virtual void ChooseState();
	virtual void ReceiveDamage(float dmg, Vector axis, DamageType type, GameObject* source);
	virtual void ExecuteState();
	virtual float TerminalVel() = 0;
	virtual void Death();
protected:
	//Set up in Initialize()
	float gsp;
	float direction;
	bool grounded;
	bool lastJumping;
	int which;
	int facing;
	int playerNo;
	float invFrames = 0;

};

#endif /* OLDSRC_PLAYER_H_ */
