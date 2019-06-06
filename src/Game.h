/*
 * Game.h
 *
 *  Created on: Jun 2, 2019
 *      Author: triforce
 */

#ifndef GAME_H_
#define GAME_H_
#include "SDLInterface.h"
#include "CollisionManager.h"
#include "GameObject.h"
class GameObject;
class Game {
public:
	Game();
	virtual ~Game();
	int Initialize();
	bool Update();
	void Close();
	SDLInterface* interface;
	CollisionManager* manager;
	int clock;
protected:
	std::forward_list<GameObject*> gameObjects;

};

#endif /* GAME_H_ */
