/*
 * GameObject.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "Physics.h"
#include "LoadingTerms.h"
class Game;
class GameObject {
public:
	GameObject(Game* game, LoadingData data) : game(game), startPos(Vector(data.x, data.y)) {
		pos=startPos;
		spawnStatus=0;
	}
	virtual ~GameObject() {

	}
	virtual void LoadResources() {

	}
	virtual void Initialize() {

	}
	virtual void Reset() {
		pos=startPos;
	}
	virtual void InitialUpdate() {

	}
	virtual void CollisionPoll() {

	}
	virtual void GeneralUpdate() {

	}
	virtual void Render() {

	}
	virtual void LateUpdate() {

	}
	virtual void ReceiveDamage(float dmg, Vector axis, DamageType type, GameObject* source) {

	}
	virtual Rect LoadingRect() {
		return Rect(pos.x, pos.y, 1, 1);
	}

	bool RespawnsOnDeath() const {
		return respawnOnDeath;
	}

	bool RespawnsOnScroll() const {
		return respawnOnScroll;
	}

	int GetSpawnStatus() const {
		return spawnStatus;
	}

	void SetSpawnStatus(int spawnStatus) {
		this->spawnStatus = spawnStatus;
	}

	const Vector GetPos() const {
		return pos;
	}

protected:
	Game* game;
	Vector startPos;
	Vector pos;
	int spawnStatus; //0=despawned, 1=alive, 2=frozen
	bool respawnOnDeath = false;
	bool respawnOnScroll = true;
};

#endif /* GAMEOBJECT_H_ */
