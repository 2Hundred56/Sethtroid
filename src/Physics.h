/*
 * Physics.h
 *
 *  Created on: Jun 2, 2019
 *      Author: triforce
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_
#include <forward_list>
#include <iostream>
#include <set>
const int SOLID = 1;
const int FOOT = 2;
const int HIT = 4;
const int HIT2 = 8;
const int TRIGGER = 16;

const int NO_UP = 1;
const int NO_LEFT = 2;
const int NO_RIGHT = 4;
const int NO_DOWN = 8;
const int NO_WEIRD = 16;

const int UP_ONLY = NO_LEFT | NO_RIGHT | NO_DOWN | NO_WEIRD;
const int LEFT_ONLY = NO_UP | NO_RIGHT | NO_DOWN | NO_WEIRD;
const int RIGHT_ONLY = NO_LEFT | NO_UP | NO_DOWN | NO_WEIRD;
const int DOWN_ONLY = NO_LEFT | NO_RIGHT | NO_UP | NO_WEIRD;
const int BAD_FLAG = NO_LEFT | NO_RIGHT | NO_DOWN | NO_UP | NO_WEIRD;
enum DamageType {
	BLUNT, SPIKE
};
struct Vector {
	float x, y;
	Vector(float x, float y) : x(x), y(y) {

	}
	Vector (const Vector& v) : x(v.x), y(v.y) {

	}
	Vector () : x(0), y(0) {

	}
};

float operator *(Vector v1, Vector v2);

bool operator <(Vector v1, Vector v2);

Vector operator *(Vector v, float f);

Vector& operator+= (Vector& orig, Vector add);

float proj(Vector v, Vector axis);

Vector operator- (Vector v);

Vector operator- (Vector, Vector);

Vector operator+ (Vector, Vector);

std::ostream& operator<<(std::ostream&, Vector);

struct Rect {
	int x, y, w, h;
	Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {

	}
	Rect() : x(0), y(0), w(0), h(0) {

	}
};

std::ostream& operator<<(std::ostream&, Rect);
Rect operator+(Rect r, Vector v);

bool RectOverlap(Rect r1, Rect r2);

class Shape {
public:
	virtual ~Shape() {

	}
	virtual std::set<Vector> Axes (Vector) = 0;
	virtual Vector Proj(Vector axis) = 0;
	virtual Rect ContainBox() = 0;
};

class AABB : public Shape {
public:
	float hw, hh;
	AABB (float w, float h) : hw(w), hh(h) {

	}
	std::set<Vector> Axes (Vector pos) {
		std::set<Vector> set;
		set.insert(Vector(1, 0));
		set.insert(Vector(0, 1));
		return set;
	}
	Vector Proj (Vector axis) {
		float p1 = proj(Vector(-hw, -hh), axis);
		float p2 = proj(Vector(hw, -hh), axis);
		float p3 = proj(Vector(hw, hh), axis);
		float p4 = proj(Vector(-hw, hh), axis);
		float max = std::max(std::max(p1, p2), std::max(p3, p4));
		float min = std::min(std::min(p1, p2), std::min(p3, p4));
		return Vector(min, max);
	}
	Rect ContainBox() {
		return Rect(-hw, -hh, hw*2, hh*2);
	}
};
class GameObject;
class CollisionInfo {
public:
	virtual void ReceiveDamage(float dmg, Vector axis, DamageType type, GameObject* source) {

	}
	virtual ~CollisionInfo() {

	}
};
class ObjectInfo : public CollisionInfo {
public:
	ObjectInfo(GameObject* obj) : obj(obj){

	}
	GameObject* obj;
	void ReceiveDamage(float dmg, Vector axis, DamageType type,
			GameObject* source);
};

class CollisionTrigger {
public:
	int id = 0;
	int cflag;
	CollisionInfo* info;
	int flag;
	Shape* shape;
	CollisionTrigger(CollisionInfo* info, Shape* shape, int flag, int cflag = 0): info(info), flag(flag), shape(shape), cflag(cflag) {
	}
	virtual const Vector GetPos() const { return pos; }
	void SetPos(const Vector pos) { this->pos = pos; }
protected:
	Vector pos;
};

int sign(float f);

struct Collision {
	CollisionInfo* otherInfo;
	Vector normal;
	Vector otherPos;
	int otherFlag;
	Collision(CollisionInfo* info, Vector n, Vector op, int f) : otherInfo(info), normal(n), otherPos(op), otherFlag(f) {

	}
};

#endif /* PHYSICS_H_ */
