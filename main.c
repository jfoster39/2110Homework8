#define REG_DISPCTL *(unsigned short *)0x4000000
#define RGB(r, g, b) ((r) | ((g)<<5) | ((b)<<10))
#define MODE3 3
#define BG2_ENABLE (1<<10)
typedef unsigned short u16;
// need extern global variable
u16 *pixelAddress = (u16 *)0x6000000;

int main(void) {
    REG_DISPCTL = MODE3 | BG2_ENABLE;
    *pixelAddress = RGB(31, 31, 31);
    pixelAddress += 239;
    *pixelAddress = RGB(31, 0, 0);
    while(1) {}
    return 0;
}
