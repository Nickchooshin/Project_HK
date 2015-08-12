#include "Input.h"

#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#elif defined(__linux__)
#include <termios.h>
#include <unistd.h>

int getch(void)
{
	termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
//#elif TARGET_OS_MAC
#endif

void Input()
{
#if defined(_WIN32) || (_WIN64)
	while (getch() != 13);
#elif defined(__linux__)
	while (getch() != 10);
//#elif defined(TARGET_OS_MAC)
#endif

	printf("\n");
}
