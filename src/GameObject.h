/*
 * GameObject.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "Game.h"
class Game;
class GameObject {
public:
	GameObject() {
	}
	virtual ~GameObject() {

	}
	virtual void LoadResources() {

	}
	virtual void InitialUpdate() {

	}
	virtual void CollisionPoll() {

	}
	virtual void GeneralUpdate() {

	}
	virtual void LateUpdate() {

	}
	virtual void Render() {

	}
protected:
	Vector pos;
};
static Game* game;
#endif /* GAMEOBJECT_H_ */
