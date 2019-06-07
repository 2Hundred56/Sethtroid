/*
 * main.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: triforce
 */
#include "Game.h"
#include <iostream>

int main( int argc, char* args[] )
{
	std::cout<<"1";
	Game* game = new Game();
	int err = game->Initialize();
	if (err!=0) return err;
	std::cout<<"6";
	while (game->Update()) {}
	game->Close();
}



