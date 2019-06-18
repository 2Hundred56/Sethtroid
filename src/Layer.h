/*
 * Layer.h
 *
 *  Created on: Jun 1, 2019
 *      Author: triforce
 */

#ifndef LAYER_H_
#define LAYER_H_
class Game;
class Layer {
public:
	Layer(Game* game) : game(game) {

	}
	virtual ~Layer() {

	}
	virtual void Render() = 0;
protected:
	Game* game;
};

#endif
