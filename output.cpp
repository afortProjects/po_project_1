#include "output.h"
void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}
void clearscreen(void)
{
	system("cls");
}
void hideCursor() {
	printf("\33[?25l");
}
void showCursor() {
	printf("\33[?25h");
}