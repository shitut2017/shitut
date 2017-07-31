#include "stdafx.h"
#include "NumericBox.h"
#include "Button.h"

using namespace std;

const int MIN_NUMERICBOX_WIDTH = 7;

NumericBox::NumericBox(short left, short top, short width,int minVal, int maxVal, size_t zOrder)
	:Panel(left,top,width,3, zOrder), _minVal(minVal),_maxVal(maxVal),_value(minVal)
{
	//the min width is to ensure that there is enough width to draw the + and - buttons
	if (width < MIN_NUMERICBOX_WIDTH)
		_width = MIN_NUMERICBOX_WIDTH;

	//numeric box is implemented as a collection of 3 controls - two buttons (+,-) and a label to show the value
	_pButtonBorderDrawer = new SingleBorderDrawer();
	_controls.push_back(new Button(left, top, 3,zOrder + 1));
	_controls.push_back(new Label(left + 3, top, width - 6,zOrder + 1));
	_controls.push_back(new Button(left + width - 3, top, 3, zOrder + 1));
	dynamic_cast<Button*>(_controls[0])->setValue("-");
	dynamic_cast<Button*>(_controls[2])->setValue("+");
	_controls[0]->setBorderDrawer(*_pButtonBorderDrawer);
	_controls[1]->setBorderDrawer(*_pButtonBorderDrawer);
	_controls[2]->setBorderDrawer(*_pButtonBorderDrawer);
	char strVal[12];
	itoa(_value, strVal, 10);
	dynamic_cast<Label*>(_controls[1])->setValue(strVal);
}

void NumericBox::updateLabelValue()
{
	char strVal[12];
	itoa(_value, strVal, 10);
	dynamic_cast<Label*>(_controls[1])->setValue(strVal);
	Graphics g;
	_controls[1]->draw(g,_left+3,_top,_zOrder+1);
}

NumericBox::~NumericBox()
{
	if (_controls[0]) delete _controls[0];
	if (_controls[1]) delete _controls[1];
	if (_pButtonBorderDrawer) delete _pButtonBorderDrawer;
}

void NumericBox::mousePressed(int x, int y, bool isLeft)
{
	//this code will work outside of an evene engine that gets the top control.
	//if combined into an event engine that gets the top control in a coordinate then we will get the the clicked event
	//of the button and we can add an actionlistener that changes the value up or down.
	
	if (y < 0 || y > 2 || x < 0 || x >= _width)
		return;
	if (x < 3)
	{
		if (_value > _minVal)
		{
			_value--;
			updateLabelValue();
		}
	}
	else if (x > _width - 3)
	{
		if (_value < _maxVal)
		{
			_value++;
			updateLabelValue();
		}
	}
}
