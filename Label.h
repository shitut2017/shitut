#pragma once
#include "TextBox.h"
class Label :
	public TextBox
{
public:
	Label(short left, short top, short width, size_t zOrder);
	virtual ~Label();

	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual bool canGetFocus() { return FALSE; };

};

