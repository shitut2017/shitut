#include "stdafx.h"
#include "ComboBox.h"
#include "Button.h"
#include "Label.h"
#include <vector>


const int MIN_COMBOBOX_WIDTH = 7;

ComboBox::ComboBox(short left, short top, short width, size_t zOrder)
	:Panel(left, top, width, 3, zOrder), _isSelectionBoxOpened(false)
{
	if (width < MIN_COMBOBOX_WIDTH)
		_width = MIN_COMBOBOX_WIDTH;

	_pButtonBorderDrawer = new SingleBorderDrawer();
	_controls.push_back(new Label(left, top, _width - 3, zOrder + 1));
	_controls.push_back(new Button(left + width - 3, top, 3, zOrder + 1));
	dynamic_cast<Button*>(_controls[1])->setValue("V");
	_controls[0]->setBorderDrawer(*_pButtonBorderDrawer);
	_controls[1]->setBorderDrawer(*_pButtonBorderDrawer);
	_selectedIndex = -1;
}

void ComboBox::drawSelectedOption(Graphics & g)
{
	Label* valueLabel = dynamic_cast<Label*>(_controls[1]);
	if (!valueLabel)
		return;
	if (_selectedIndex == -1 || _options.size() == 0)
		valueLabel->setValue("");
	else
		valueLabel->setValue(_options[_selectedIndex]);
	valueLabel->draw(g,_zOrder);
}

ComboBox::~ComboBox()
{
	if (_controls[0]) delete _controls[0];
	if (_controls[1]) delete _controls[1];
	if (_pButtonBorderDrawer) delete _pButtonBorderDrawer;
}

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	
}

void ComboBox::keyDown(int keyCode, char charecter)
{

}
