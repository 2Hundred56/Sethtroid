#include "Physics.h"
#include "GameObject.h"
#include <cmath>
 void ObjectInfo::ReceiveDamage(float dmg, Vector axis, DamageType type,
		GameObject* source) {
	obj->ReceiveDamage(dmg, axis, type, source);
}
float operator *(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

bool operator <(Vector v1, Vector v2) {
	return v1.x < v2.x;
}

Vector operator *(Vector v, float f) {
	return Vector(v.x * f, v.y * f);
}

float proj(Vector v, Vector axis) {
	//Assume axis is normalized
	return axis * v;
}

Vector operator -(Vector v) {
	return Vector(-v.x, -v.y);
}

std::ostream& operator <<(std::ostream& out, Vector v) {
	out<<"<"<<v.x<<","<<v.y<<">";
	return out;
}

std::ostream& operator <<(std::ostream& out, Rect r) {
	out<<"["<<r.x<<","<<r.y<<","<<r.w<<","<<r.h<<"]";
	return out;
}

Vector operator -(Vector v1, Vector v2) {
	return Vector(v1.x-v2.x, v1.y-v2.y);
}

Vector operator +(Vector v1, Vector v2) {
	return Vector(v1.x+v2.x, v1.y+v2.y);
}

Vector& operator +=(Vector& orig, Vector add) {
	orig = Vector(orig.x+add.x, orig.y+add.y);
	return orig;
}

int sign(float f) {
	if (f < 0)
		return -1;
	else if (f > 0)
		return 1;
	else
		return 0;
}

Rect operator +(Rect r, Vector v) {
	return Rect(r.x+v.x, r.y+v.y, r.w, r.h);
}

bool RectOverlap(Rect r1, Rect r2) {
	if ( std::abs((2*r1.x+r1.w) - (r2.x*2 + r2.w)) > (r1.w+r2.w) ) return false;
	if ( std::abs((2*r1.y+r1.h) - (r2.y*2 + r2.h)) > (r1.h+r2.h) ) return false;
	return true;
}
/*
 * Physics.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: triforce
 */




