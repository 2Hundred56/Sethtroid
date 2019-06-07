/*
 * Animation.h
 *
 *  Created on: Jun 5, 2019
 *      Author: triforce
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Sprite.h"
#include "AnimationResource.h"
class Animation: public Sprite {
public:
	Animation() : Sprite(0, 0){

	}
	virtual ~Animation() {

	}
	int GetWidth() {
		return wrapper->GetWidth(index);
	}
	int GetHeight() {
		return wrapper->GetHeight(index);
	}
	unsigned int PixelAt(int x, int y) {
		return wrapper->PixelAt(index, x, y);
	}
	char GetData(int x, int y) {
		return wrapper->GetData(index, x, y);
	}
	void Advance(int t) {
		if (t%wrapper->interval==0) {
			index++;
			if (index>=wrapper->numFrames) index=0;
		}
	}
	int index = 0;
	AnimationResource* wrapper;



};

#endif /* ANIMATION_H_ */
