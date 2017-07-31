// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

void print_button(HANDLE h, short start_x, short start_y, short len_x, short len_y) {
	COORD c = { start_x, start_y };
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

	//first button
	printf("%c", '\xDA');
	short i;
	for (i = 0; i < len_x; i++) {
		printf("%c", '\xC4');
	}
	printf("%c", '\xBF');
	for (i = 1; i < len_y; i++) {
		c = { start_x, start_y + i };
		SetConsoleCursorPosition(h, c);
		printf("%c", '\xB3');
		c = { start_x+len_x+1, start_y+i };
		SetConsoleCursorPosition(h, c);
		printf("%c", '\xB3');
	}
	c = { start_x, start_y + i };
	SetConsoleCursorPosition(h, c);
	printf("%c", '\xc0');
	for (short i = 0; i < len_x; i++) {
		printf("%c", '\xC4');
	}
	printf("%c", '\xd9');
	//end first button
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	c = { start_x+1,start_y+1 };
	SetConsoleCursorPosition(h, c);
	printf("click me");
	
}
/*
void main()
{

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	

	print_button(h, 7, 7, 10, 2);
	print_button(h, 7, 11, 10, 2);

	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	HANDLE hinput = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hinput, ENABLE_MOUSE_INPUT);
	INPUT_RECORD r[10] = { 0 };
	DWORD input_read = 0;
	BOOLEAN clicked = FALSE;
	short i;
	while (1)
	{
		ReadConsoleInput(hinput, r, 10, &input_read);
		for (i = 0; i < input_read; i++) {
			switch (r[i].EventType) {
			case MOUSE_EVENT:
				MOUSE_EVENT_RECORD mer = r[i].Event.MouseEvent;
				if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)  //if clicked
				{
					if (mer.dwMousePosition.X >= 7 && mer.dwMousePosition.X<=18)
						if (mer.dwMousePosition.Y >= 7 & mer.dwMousePosition.Y <= 10)
						{
							SetConsoleCursorPosition(h, { 18,10 });
							if (!clicked)
							{
								printf("button clicked");
								clicked = TRUE;
							}
							else {
								for (int j = 0; j < strlen("button clicked"); j++) printf(" ");
								clicked = FALSE;
							}
						}
				}
				break;
			case KEY_EVENT:
				KEY_EVENT_RECORD ker = r[i].Event.KeyEvent;
				if (!ker.bKeyDown) break;
				if (ker.wVirtualKeyCode != VK_TAB) break;
				CONSOLE_SCREEN_BUFFER_INFO info;
				GetConsoleScreenBufferInfo(h, &info);
				if (info.dwCursorPosition.Y == 12)
					SetConsoleCursorPosition(h, { 8,8 });
				else
					SetConsoleCursorPosition(h, { 8,12 });
			}
		}
		
	}
}

*/