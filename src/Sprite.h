/*
 * Sprite.h
 *
 *  Created on: Jun 14, 2019
 *      Author: triforce
 */

#ifndef SPRITE_H_
#define SPRITE_H_

class Sprite {
public:
	Sprite() {

	}
	~Sprite() {

	}
	void FillBlack() {
		palettes[0] = 0x000000FF;
		for (int i=0; i<width; i++) {
			for (int j=0; j<height; j++) {
				data[i][j]=0;
			}
		}
	}
	unsigned int PixelAt(int x, int y) const { return palettes[data[x][y]]; }
	void CopyData(const Sprite* other) {
		numPalettes= other->numPalettes;
		for(int i = 0; i < numPalettes; ++i) palettes[i] = other->GetPalette(i);
		int w = other->GetWidth();
		int h = other->GetHeight();
		data = new char*[w];
		for(int i = 0; i < w; ++i) data[i] = new char[h];
		for (int i=0; i<w; i++) {
			for (int j=0; j<h; j++) {
				data[i][j]=other->GetData(i, j);
			}
		}
		width=w;
		height=h;
	}
	int GetHeight() const { return height; }
	int GetWidth() const { return width; }
	int GetPalette(int i) const { return palettes[i]; }
	int NumPalettes() const {return numPalettes;}
	void SetPalette(int i, unsigned int pixel) { palettes[i]=pixel; if (numPalettes<(i+1)) numPalettes=i+1;}
	void SetPixel(int i, int j, char k) { data[i][j]=k; }
	char GetData(int i, int j) const {return data[i][j];}
protected:
	char** data;
	int width, height;
	unsigned int* palettes;
	int numPalettes = 0;
};

#endif /* SPRITE_H_ */
