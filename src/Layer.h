/*
 * Layer.h
 *
 *  Created on: Jun 1, 2019
 *      Author: triforce
 */

#ifndef LAYER_H_
#define LAYER_H_

class Layer {
public:
	virtual unsigned int PixelAt(int, int) = 0;
};

#endif /* LAYER_H_ */
