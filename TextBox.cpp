#include "stdafx.h"
#include "TextBox.h"
#include <iostream>
using namespace std;
TextBox::TextBox(short left, short top, short width, size_t zOrder)
	:Control(left,top,width,3,zOrder)
{
	_cursorIndex = 0;
	_maxLetters = (width - 2);//two for border
	_text.resize(_maxLetters + 1);//for '\0'
	_text[0] = '\0';
	_dummySpace[0] = '\0';
	_dummySpace.insert(0, _maxLetters, ' ');
}

TextBox::~TextBox()
{
}

const int KK_LEFT	= 37;
const int KK_UP		= 38;
const int KK_RIGHT	= 39;
const int KK_DOWN	= 40;
const int KK_LC_A	= 97;
const int KK_LC_Z	= 122;
const int KK_UC_A	= 65;
const int KK_UC_Z	= 90;
const int KK_0		= 48;
const int KK_9		= 57;
const int KK_BACKSPACE = 8;
const int KK_DEL = 46;

void TextBox::drawImpl(Graphics& g, unsigned int l, unsigned int t, size_t z)
{
	g.moveTo(l, t);
	g.write(_dummySpace);
	g.moveTo(l, t);
	g.write(_text);
};

bool TextBox::isValidTextChar(int KeyCode)
{
	if (KeyCode >= KK_LC_A && KeyCode <= KK_LC_Z)
		return true;
	else if (KeyCode >= KK_UC_A && KeyCode <= KK_UC_Z)
		return true;
	else if (KeyCode >= KK_0 && KeyCode <= KK_9)
		return true;
	else
		return false;
}
void TextBox::keyDown(int keyCode, char charecter)
{
	Graphics g;
	POINT pt;
	GetCursorPos(&pt);

	if (keyCode == KK_LEFT)
	{
		if (pt.x == _left + 1 && pt.y == _top + 1)
		{
			return;
		}
		else if (pt.x == _left + 1)
		{
			g.moveTo(_left + _width - 1, pt.y - 1);
			_cursorIndex--;
		}
		else
		{
			g.moveTo(pt.x - 1, pt.y);
			_cursorIndex--;
		}
	}
	else if (keyCode == KK_RIGHT)
	{
		if (pt.x == _left + _width - 1 && pt.y == _top + _height + -1)
		{
			return;
		}
		if (_cursorIndex == _text.size()-1)
		{
			return;
		}
		else if (pt.x == _left + _width - 1)
		{
			g.moveTo(_left + 1, pt.y + 1);
			_cursorIndex++;
		}
		else
		{
			g.moveTo(pt.x + 1, pt.y);
			_cursorIndex++;
		}
	}
	else if (keyCode == KK_DEL)
	{
		if (_text.size() <= 1 || _cursorIndex == _text.size())
		{
			return;
		}
		_text.erase(_cursorIndex, 1);

		drawImpl(g, _left + 1, _top + 1,0);
		g.moveTo(_left + 1 + _cursorIndex, _top + 1);
	}
	else if (keyCode == KK_BACKSPACE)
	{
		if (_text.size() <= 1 || _cursorIndex == 0)
		{
			return;
		}
		_text.erase(_cursorIndex - 1, 1);
		_cursorIndex--;

		drawImpl(g, _left + 1, _top + 1,0);
		g.moveTo(_left + 1 + _cursorIndex, _top + 1);
	}
	else if (isValidTextChar(keyCode))
	{
		if (_text.size() == _maxLetters)
		{
			return;
		}
		else
		{
			_text.insert(_cursorIndex, 1, charecter);
			_cursorIndex++;
			drawImpl(g, _left + 1, _top + 1,0);
			g.moveTo(_left + 1 + _cursorIndex, _top + 1);
			_cursorIndex++;
		}
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	if (isLeft)
	{
		Graphics g;
		if (x == 0) x = 1;
		if (y == 0) y = 1;
		if (x == _width) x = _width - 1;
		if (y == _height) y = _height - 1;

		g.moveTo(x, y);
		g.moveTo(3, 0);
		_cursorIndex = x - _left;
		g.setCursorVisibility(true);

	}
}

void TextBox::setValue(string text)
{
	if (text.size() <= _maxLetters)
	{
		_text = text;
	}
	else
	{
		_text = text.substr(0, _maxLetters);
	}
};
