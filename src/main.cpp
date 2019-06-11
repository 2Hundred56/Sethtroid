/*
 * main.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: triforce
 */
#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>
#include "CollisionManager.h"

int main( int argc, char* args[] )
{
	//CollisionManager* manager = new CollisionManager(10, 10);
	///std::cout<<manager->CheckCollision(new AABB(0.5, 8), Vector(91.5,125.2), new AABB(8, 8), Vector(104, 136), LEFT_ONLY);
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::duration<float> fsec;
	auto t0 = Time::now();
	auto t1 = Time::now();
	float dt;
	float overflow = 0;
	Game* game = new Game();
	game->Initialize();
	while (true) {
		dt = ((fsec) (t1 - t0)).count();
		overflow+=dt;
		if (overflow>(1.0/2.0)) {
			if (!game->Update()) break;
			overflow=0;
		}
		t0=t1;
		t1=Time::now();
	}
	game->Close();
}



