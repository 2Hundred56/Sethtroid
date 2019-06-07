#ifndef SPRITE_H_
#define SPRITE_H_
#include <iostream>
class Sprite {
public:
	Sprite(int, int);
	virtual ~Sprite();
	void FillBlack();
	unsigned int PixelAt(int x, int y);
	void CopyData(Sprite*);
	virtual int GetHeight() const { return height; }
	virtual int GetWidth() const { return width; }
	int GetPalette(int i) const { return palettes[i]; }
	void SetPalette(int i, unsigned int pixel) { palettes[i]=pixel; if (numPalettes<(i+1)) numPalettes=i+1;}
	void SetPixel(int i, int j, char k) { data[i][j]=k; }
	char GetData(int i, int j) {return data[i][j];}
	bool HFLIPPED=false;
	char** data;
	int width, height;
	unsigned int* palettes;
	int numPalettes = 0;

};
#endif /* SPRITE_H_ */
