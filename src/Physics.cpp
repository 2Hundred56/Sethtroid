#include "Physics.h"
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
/*
 * Physics.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: triforce
 */




