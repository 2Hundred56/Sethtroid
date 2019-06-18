/*
 * LoadingTerms.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef LOADINGTERMS_H_
#define LOADINGTERMS_H_
class LoadingData {
public:
	LoadingData(int x, int y) {
		this->x=x; this->y=y;
	}
	int x, y;
};

class PlayerData : public LoadingData {
public:
	int playerNo;
	int which;
	PlayerData(int x, int y, int which, int playerNo) : LoadingData(x, y) {
		this->which=which;
		this->playerNo = playerNo;
	}
};

#endif /* LOADINGTERMS_H_ */
