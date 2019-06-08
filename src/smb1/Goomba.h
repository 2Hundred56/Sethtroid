/*
 * Goomba.h
 *
 *  Created on: Jun 7, 2019
 *      Author: triforce
 */

#ifndef SMB1_GOOMBA_H_
#define SMB1_GOOMBA_H_
#include "../PhysicsObject.h"
#include "../Animation.h"
namespace smb1 {

class Goomba: public PhysicsObject {
public:
	Goomba(Game* game) : GameObject(game), PhysicsObject(game){

	}
	virtual ~Goomba() {

	}
	void GeneralUpdate() {
		PhysicsObject::GeneralUpdate();
		anim->Advance(game->clock);
		std::cout<<displacement<<"\n"<<std::flush;
		if (displacement.x!=0) {
			sgn*=-1;
		}
		if (displacement.y<0) {
			velocity.y=0;
		}
		else {
			velocity.y+=0.375;
		}
		velocity.x = sgn*0.75;
	}
	void Render() {
		Vector choice = pos-Vector(anim->GetWidth()/2.0, anim->GetHeight()/2.0);
		game->interface->BlitSprite(anim, (int) choice.x, (int) choice.y);
	}
	void LoadResources() {
		anim=new Animation(game->interface->LoadAnim("rsrc/smb1/goomba.bin"));
		velocity=Vector(0.75, 0);
		trigger=new CollisionTrigger(new CollisionInfo(), new AABB(9, 9), FOOT|TRIGGER);
	}
protected:
	int sgn = 1;
	Animation* anim;

};

} /* namespace smb1 */

#endif /* SMB1_GOOMBA_H_ */
