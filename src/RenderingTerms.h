/*
 * RenderingTerms.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef RENDERINGTERMS_H_
#define RENDERINGTERMS_H_
enum RenderRotation {
	NONE, XFLIP, YFLIP, XYFLIP
};
struct RenderData {
	RenderRotation rot;
	RenderData(RenderRotation rot) : rot(rot) {

	}
	RenderData() : rot(NONE) {

	}
};



#endif /* RENDERINGTERMS_H_ */
