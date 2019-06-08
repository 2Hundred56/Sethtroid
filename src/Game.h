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
	SDLInterface* interface = NULL;
	CollisionManager* manager = NULL;
	int clock = 0;
	bool paused=false;
protected:
	std::forward_list<GameObject*> gameObjects;
	std::vector<TileLayer*> layers;


};

#endif /* GAME_H_ */
