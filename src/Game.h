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
#include "ThreeBy3.h"
class Game {
public:
	Game();
	virtual ~Game();
	int Initialize();
	bool Update();
	void Close();
protected:
	SDLInterface* interface;
	CollisionManager* manager;
	ThreeBy3* t3;
	Tileset* tileset;
	TileLayer* layer;
	Sprite* sprite;

};

#endif /* GAME_H_ */
