#include "stdafx.h"
#include "RadioBox.h"
#include "Button.h"
#include "Label.h"

const int MIN_RadioBox_WIDTH = 7;


RadioBox::RadioBox(short left, short top, short width, size_t zOrder,int numOfOpetions)
        :Panel(left, top, width, 3, zOrder), _isSelectionBoxOpened(false)
{
    if (width < MIN_RadioBox_WIDTH)
        _width = MIN_RadioBox_WIDTH;

    _pButtonBorderDrawer = new SingleBorderDrawer();
    _controls.push_back(new Label(left, top, _width - 3, zOrder + 1));
    _controls.push_back(new Button(left + width - 3, top, 3, zOrder + 1));
    dynamic_cast<Button*>(_controls[1])->setValue("V");
    _controls[0]->setBorderDrawer(*_pButtonBorderDrawer);
    _controls[1]->setBorderDrawer(*_pButtonBorderDrawer);
    _selectedIndex = -1;

    for (int i -0; i<numOfOpetions; i++) {
        this._options.addOption("0");
    }
}

void Radiobox::drawSelectedOption(Graphics & g)
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

Radiobox::~Radiobox()
{
    if (_controls[0]) delete _controls[0];
    if (_controls[1]) delete _controls[1];
    if (_pButtonBorderDrawer) delete _pButtonBorderDrawer;
}

void Radiobox::mousePressed(int x, int y, bool isLeft)
{

}

void Radiobox::keyDown(int keyCode, char charecter)
{

}
int Radiobox::GetSelectedIndex()
{
    return this._selectedIndex;
}
void RadioBox::SetSelectedIndex(int index)
{
    for (int i =0; i<_options.size; i++) {
        _options.at(i) = "0";
    }
    this._selectedIndex = index
    _options.at(i) = "1";

}
