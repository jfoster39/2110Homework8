#define REG_DISPCTL *(unsigned short *)0x4000000
#define RGB(r, g, b) ((r) | ((g)<<5) | ((b)<<10))
#define MODE3 3
#define BG2_ENABLE (1<<10)
#define RED RGB(31, 0, 0)
typedef unsigned short u16;
extern u16 *videoBuffer;

void setPixel(int r, int c, u16 color);
void drawRect(int r, int c, int width, int height, u16 color);
void drawHollowRect(int r, int c, int width, int height, u16 color);

int main(void) {
	// Set up the Display control register to mode3, and BG2 enabled
    REG_DISPCTL = MODE3 | BG2_ENABLE;

    int i;
    for (i = 0; i<5; i++) {
    	setPixel(i, 0, RED);
    }

    drawRect(100, 100, 5, 3, RED);
    drawHollowRect(20, 7,6, 3, RED);

    while(1) {}
    return 0;
}
