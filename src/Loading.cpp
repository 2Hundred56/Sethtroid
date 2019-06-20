/*
 * Loading.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: triforce
 */
#include "Game.h"
#include "smb1/Mario.h"
#include "SDLInterface.h"
#include "LoadingTerms.h"
#include "TileLayer.h"
#include <iostream>
void Game::LoadLevel(char* path, int chunk, int entranceData) {
	std::cout<<"Loading level "<<path<<"...\n"<<std::flush;
	std::ifstream file (path, std::ios::in | std::ios::binary);
	std::cout<<"Loading header..."<<std::flush;
	char buffer1[2];
	char buffer2[2];
	char address[6];
	file.seekg(chunk*6);
	file.read(address, 6);
	file.seekg((((long) address[0])<<40)+(((long) address[1])<<32)+(((long) address[2])<<24)+(((long) address[3])<<16)+(((long) address[4])<<8)+((long) address[5]));
	file.read(buffer1, 2);
	file.read(buffer2, 2);
	worldSize = Vector(buffer1[0]*256+buffer1[1], buffer2[0]*256+buffer2[1]);
	file.read(buffer1, 2);
	for (int i=0; i<(buffer1[0]*256+buffer1[1]); i++) {
		//process declaration
	}
	std::cout<<"Done.\n"<<std::flush;
	std::cout<<"Loading layers..."<<std::flush;
	Layer* layerPointer = 0;
	while (true) {
		layerPointer = LoadLayer(&file);
		if (layerPointer!=0) AddLayer(layerPointer);
		else break;
	}
	std::cout<<"Done.\n"<<std::flush;
	std::cout<<"Loading objects..."<<std::flush;
	GameObject* goPointer = 0;
	while (true) {
		goPointer = LoadObject(&file);
		if (goPointer!=0) AddObject(goPointer);
		else break;
	}
	std::cout<<"Done.\n"<<std::flush;
}

GameObject* Game::LoadObject(std::ifstream* input) {
	char buffer[2];
	input->read(buffer, 2);
	int objectType=(buffer[0]<<8)+buffer[1];

	if (objectType==0) {

		return 0;
	}
	else if (objectType==1) {

		char marioData[8];
		input->read(marioData, 8);
		smb1::Mario* mario = new smb1::Mario(this, PlayerData(marioData[0]*256+marioData[1],marioData[2]*256+marioData[3], 0, marioData[4]));
		mario->LoadResources();
		return mario;
	}
	else {
		return 0;
	}
}

Layer* Game::LoadLayer(std::ifstream* input) {
	char layerType[1];
	input->read(layerType, 1);
	if ((int) layerType[0]==((int) 0)) {
		return 0;
	}
	else if (layerType[0]==1) {
		int tileWidth;
		int tileHeight;
		char buffer[1];
		char buffer2[2];
		input->read(buffer2, 2);
		tileWidth=buffer2[0]*255+buffer2[1];
		input->read(buffer2, 2);
		tileHeight=buffer2[0]*255+buffer2[1];
		input->read(buffer, 1);
		TileLayer* layer = new TileLayer(this, tileWidth, tileHeight, buffer[0]);
		input->read(buffer, 1);
		char tileData[2];
		Tileset* set = 0;
		for (int i=0; i<buffer[0]; i++) {
			input->read(tileData, 2);
			switch (255*tileData[0]+tileData[1]) {
			case 0:
				set=interface->GetTileset("SMB1-Tileset-Grass");
				break;
			}
		}
		for (int j=0; j<tileHeight; j++) {
			for (int i=0; i<tileWidth; i++) {
				input->read(buffer2, 2);
				layer->SetTile(i, j, buffer2[0], buffer2[1]);
			}
		}
		return layer;

	}
}


void Game::LoadResources() {
	interface->LoadAnimation("rsrc/smb1/mario/mario-idle.bin", "SMB1-Mario-Idle");
	interface->LoadAnimation("rsrc/smb1/mario/mario-brake.bin", "SMB1-Mario-Brake");
	interface->LoadAnimation("rsrc/smb1/mario/mario-run.bin", "SMB1-Mario-Run");
	interface->LoadAnimation("rsrc/smb1/mario/mario-jump.bin", "SMB1-Mario-Jump");
	interface->LoadTileset("rsrc/smb1/grassTileset.bin", "SMB1-Tileset-Grass");
}
