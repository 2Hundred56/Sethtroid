/*
 * Mario.h
 *
 *  Created on: Jun 6, 2019
 *      Author: triforce
 */

#ifndef SMB1_MARIO_H_
#define SMB1_MARIO_H_
#include "../Player.h"
namespace SMB1 {

class Mario: public Player {
public:
	Mario();
	virtual ~Mario();
	bool IsRunning() {return game->interface->isRunning;}
	Vector Gravity() {
		if (game->interface->isJumping && state==JUMPING) {
			return Vector(0, 0.15625);
		}
		else {
			return Vector(0, 0.5625);
		}
	}
	float Accel() {
		if (IsRunning()) {
			return 0.054745;
		}
		else {
			return 0.035278;
		}
	}
	float Decel() {
		return 0.101563;
	}
	float TopSpeed() {
		if (IsRunning()) return 2.5625;
		else return 1.5625;
	}
	float AirAccel() {
		if (IsRunning()) return 0.0508422;
		else return 0.0352783;
	}
	float AirDecel() {
		if (IsRunning()) return 0.0508422;
		else return 0.0352783;
	}
};

} /* namespace SMB1 */

#endif /* SMB1_MARIO_H_ */
