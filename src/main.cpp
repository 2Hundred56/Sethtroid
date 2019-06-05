/*
 * main.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: triforce
 */
#include "Game.h"


int main( int argc, char* args[] )
{
	Game* game = new Game();
	int err = game->Initialize();
	if (err!=0) return err;
	while (game->Update()) {}
	game->Close();
}



