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


int main( int argc, char* args[] )
{

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
		if (overflow>(1.0/60.0)) {
			if (!game->Update()) break;
			overflow=0;
		}
		t0=t1;
		t1=Time::now();
	}
	game->Close();
}



