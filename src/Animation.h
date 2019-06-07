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
	Animation(AnimationResource* res) : Sprite(0, 0), wrapper(res){

	}
	virtual ~Animation() {

	}
	int GetWidth() const {
		return wrapper->GetWidthI(index);
	}
	int GetHeight() const {
		return wrapper->GetHeightI(index);
	}
	unsigned int PixelAt(int x, int y) {
		return wrapper->PixelAtI(index, x, y, HFLIPPED);
	}
	char GetData(int x, int y) {
		return wrapper->GetDataI(index, x, y, HFLIPPED);
	}
	void Advance(int t) {
		if (t%wrapper->interval==0) {
			index++;
			if (index>=wrapper->NumFrames()) index=0;
		}
	}
	int index = 0;
	AnimationResource* wrapper;




};

#endif /* ANIMATION_H_ */
