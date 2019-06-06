/*
 * SpritedObject.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#include "SpritedObject.h"

SpritedObject::SpritedObject() : GameObject() {
	// TODO Auto-generated constructor stub

}

SpritedObject::~SpritedObject() {
	// TODO Auto-generated destructor stub
}

void SpritedObject::Render() {
	Vector choice = pos-Vector(sprite->GetWidth()/2.0, sprite->GetHeight()/2.0);
	game->interface->BlitSprite(sprite, choice.x, choice.y);
}
