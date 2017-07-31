#include "stdafx.h"
#include "Control.h"


Control* Control::_controlInFocus = NULL;

Control::Control(short left, short top, short width, short height,size_t zOrder)
	:_left(left),_top(top),_width(width),_height(height),_zOrder(zOrder)
{
	_pBorderDrawer = NULL;
}


Control::~Control()
{
}


void Control::draw(Graphics& g, int x, int y, size_t z)
{
	if (z > _zOrder)
		return;
	
	if (_pBorderDrawer)
	{
		_pBorderDrawer->draw(g, _left + x, _top + y, _width, _height);
	}
	drawImpl(g, _left + x + 1, _top + y + 1, z);
	g.setCursorVisibility(false);
};

void Control::draw(Graphics& g, size_t z)
{
	if (z > _zOrder)
		return;

	if (_pBorderDrawer)
	{
		_pBorderDrawer->draw(g, _left, _top, _width, _height);
	}
	drawImpl(g, _left + 1, _top + 1, _zOrder);
	g.setCursorVisibility(false);
};