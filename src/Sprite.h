class Sprite {
public:
	Sprite(int, int);
	virtual ~Sprite();
	void FillBlack();
	unsigned int PixelAt(int x, int y);
	void CopyData(Sprite*);
	int GetHeight() const { return height; }
	int GetWidth() const { return width; }
	int GetPalette(int i) const { return palettes[i]; }
	void SetPalette(int i, unsigned int pixel) { palettes[i]=pixel; x++;}
	void SetPixel(int i, int j, char k) { data[i][j]=k; }
	char GetData(int i, int j) {return data[i][j];}
	int x;
protected:
	int width, height;
	unsigned int* palettes;
	char** data;

};
