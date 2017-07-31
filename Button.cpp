#include "stdafx.h"
#include "Button.h"


Button::Button(short left, short top, short width,size_t zOrder)
	:Label(left,top,width,zOrder)
{
}

Button::~Button()
{
}

void Button::mousePressed(int x, int y, bool isLeft)
{
	for (int i = 0; i < _listeners.size(); i++)
	{
		_listeners[i]->action();
	}
}

void Button::addListener(IListener * listener)
{
	_listeners.push_back(listener);
}