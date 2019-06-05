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
const int TRIGGER = 8;
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
	float x, y, w, h;
	Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {

	}
};

class Shape {
public:
	virtual std::set<Vector> Axes (Vector) = 0;
	virtual Vector Proj(Vector axis) = 0;
	virtual Rect ContainBox(Vector pos) = 0;
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
	Rect ContainBox(Vector pos) {
		return Rect(pos.x-hw, pos.y-hh, hw*2, hh*2);
	}
};

struct CollisionInfo {

};

class CollisionTrigger {
public:
	float id;
	Vector pos;
	CollisionInfo info;
	int flag;
	Shape* shape;
};

int sign(float f);

struct Collision {
	CollisionInfo otherInfo;
	Vector normal;
	Vector otherPos;
	int otherFlag;
	Collision(CollisionInfo info, Vector n, Vector op, int f) : otherInfo(info), normal(n), otherPos(n), otherFlag(f) {

	}
	Collision() {

	}
};



#endif /* PHYSICS_H_ */
