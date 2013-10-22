typedef unsigned short u16;
u16 *videoBuffer = (u16 *)0x6000000;

void setPixel(int r, int c, u16 color);
void drawRect(int r, int c, int width, int height, u16 color);
void drawHollowRect(int r, int c, int width, int height, u16 color);

void setPixel(int r, int c, u16 color) {
    videoBuffer[r*240 + c] = color;
}

void drawRect(int r, int c, int width, int height, u16 color) {

}

void drawHollowRect(int r, int c, int width, int height, u16 color) {

}