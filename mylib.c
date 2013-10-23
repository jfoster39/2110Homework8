typedef unsigned short u16;
u16 *videoBuffer = (u16 *)0x6000000;

void setPixel(int r, int c, u16 color);
void drawRect(int r, int c, int width, int height, u16 color);
void drawHollowRect(int r, int c, int width, int height, u16 color);

/**
Follows formula for calculating where to set the pixel. 
**/
void setPixel(int r, int c, u16 color) {
    videoBuffer[(r*240 + c)] = color;
}

void drawRect(int r, int c, int width, int height, u16 color) {
	int i;
	int j;
	int cReset = c;
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			setPixel(r, c ,color);
			c++;
		}
	c = cReset;
	r++;
	}
}

/**
Here we draw 4 seperate rectangles for the outline of a hollow rectangle.
We first draw the top row, then the leftmost coloumn. We then draw the 
bottom rectangle, and then the rightmost. 
**/
void drawHollowRect(int r, int c, int width, int height, u16 color) {
    drawRect(r, r, width, 1, color);
	drawRect(r, r, 1, height, color);
    drawRect(r+height, r, 1, height, color);
    drawRect(r, c+width, width, 1, color);
}