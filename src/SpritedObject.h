/*
 * SpritedObject.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef SPRITEDOBJECT_H_
#define SPRITEDOBJECT_H_

#include "GameObject.h"

class SpritedObject: public GameObject {
public:
	SpritedObject();
	virtual ~SpritedObject();
	virtual void Render();
protected:
	Sprite* sprite;
};

#endif /* SPRITEDOBJECT_H_ */
