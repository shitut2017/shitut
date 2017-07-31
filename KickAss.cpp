#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void kamain()
{






	//set cursor position example
	INPUT_RECORD ir[5] = { 0 };
	DWORD num_read;

	srand(time(0));

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hinput = GetStdHandle(STD_INPUT_HANDLE);





	COORD c = { 7, 7 };

	SetConsoleCursorPosition(h, c);
	SetConsoleMode(hinput, ENABLE_MOUSE_INPUT);




	const char CORNER_TL	= '\xDA';
	const char LINE_L		= '\xB3';
	const char CORNER_BL	= '\xC0';
	const char LINE_B		= '\xC4';
	const char CORNER_BR	= '\xD9';
	const char LINE_R		= '\xB3';
	const char CORNER_TR	= '\xBF';
	const char LINE_T		= '\xC4';

	const char CORNER_TL_D	= '\xC9';
	const char LINE_L_D		= '\xBA';
	const char CORNER_BL_D	= '\xC8';
	const char LINE_B_D	    = '\xCD';
	const char CORNER_BR_D	= '\xBC';
	const char LINE_R_D     = '\xBA';
	const char CORNER_TR_D  = '\xBB';
	const char LINE_T_D     = '\xCD';



	printf("%c", CORNER_TL);
	printf("%c", LINE_L);
	printf("%c", CORNER_BL);
	printf("%c", LINE_B);
	printf("%c", CORNER_BR);	
	printf("%c", LINE_R);
	printf("%c", CORNER_TR);
	printf("%c", LINE_T);
	printf("%c", CORNER_TL_D);
	printf("%c", LINE_L_D);
	printf("%c", CORNER_BL_D);
	printf("%c", LINE_B_D);
	printf("%c", CORNER_BR_D);
	printf("%c", LINE_R_D);
	printf("%c", CORNER_TR_D);
	printf("%c", LINE_T_D);

	printf("%c", '\xDA');
	for (short i = 0; i < 5; i++) {
		printf("%c", '\xC4');
	}
	printf("%c", '\xBF');
	for (short i = 1; i < 5; i++) {
		c = { 7, 7+i };
		SetConsoleCursorPosition(h, c);
		printf("%c", '\xB3');
		c = { 13, 7 + i };
		SetConsoleCursorPosition(h, c);
		printf("%c", '\xB3');
	}
	c = { 7, 12 };
	SetConsoleCursorPosition(h, c);
	printf("%c", '\xc0');
	for (short i = 0; i < 5; i++) {
		printf("%c", '\xC4');
	}
	printf("%c", '\xd9');
	
	



	while (1) {
		ReadConsoleInput(hinput, ir, 5, &num_read);
		DWORD rndBG = rand() % 16;
		DWORD rndFG = rand() % 16;
		DWORD wAttr = rndFG | (rndBG << 4);

		SetConsoleTextAttribute(h, wAttr);
		if (num_read) {
			for (int i=0; i<num_read; i++) {
				switch (ir[i].EventType) {
				case KEY_EVENT:
					printf("key %s it's virtual key code value %d\n",
						ir[i].Event.KeyEvent.bKeyDown ? "down" : "up",
						ir[i].Event.KeyEvent.wVirtualKeyCode);
					break;
				case MOUSE_EVENT:
					printf("mouse event\n");
					break;
				}
			}
		}
		
	}

	//set cursor size and visibility example

	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(h, &cci);
	/*
	//set foreground color

	DWORD wAttr = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(h, wAttr);

	printf("hello yellow ? world\n");

	CONSOLE_SCREEN_BUFFER_INFO cbi;

	GetConsoleScreenBufferInfo(h, &cbi);

	DWORD wAttr2 = cbi.wAttributes | BACKGROUND_BLUE | BACKGROUND_GREEN;
	SetConsoleTextAttribute(h, wAttr2);

	printf("ugly background yellow foreground\n");

	GetConsoleScreenBufferInfo(h, &cbi);

	DWORD a = cbi.wAttributes | BACKGROUND_INTENSITY;
	SetConsoleTextAttribute(h, a);


	//what color will that print ?
	printf("hello  ??? world\n");

	GetConsoleScreenBufferInfo(h, &cbi);
	a = cbi.wAttributes | COMMON_LVB_REVERSE_VIDEO;
	SetConsoleTextAttribute(h, a);

	printf("and now ?");

	getchar();
	*/

	//last: ReadConsoleInput

}
