#include "stdafx.h"
#include "Panel.h"

Panel::Panel(short left, short top, short width, short height,size_t zOrder)
	:Control(left, top, width, height,zOrder)
{
}

Panel::~Panel()
{
}

void Panel::addControl(Control* pControl)
{
	pControl->setLeft(pControl->getLeft() + _left + 1);
	pControl->setTop(pControl->getTop() + _top + 1);
	_controls.push_back(pControl);
}

void Panel::drawImpl(Graphics& g, unsigned int l, unsigned int t,size_t z)
{
	for (int i = 0; i < _controls.size(); i++)
	{
		int left = _controls[i]->getLeft();
		int top = _controls[i]->getTop();
		_controls[i]->draw(g, z + 1);
	}
}

Control* Panel::findTopControl(int x, int y)
{
	//returns the control with the highest zOrder in this x,y coordination
	Control* pTopControl = NULL;
	vector<Control*> allControls;
	getAllControls(&allControls);
	for (int i = 0; i < allControls.size(); i++)
	{
		if (isInside(x, y, allControls[i]->getLeft(), allControls[i]->getTop(), allControls[i]->getWidth(), allControls[i]->getHeight()) == true)
		{
			if (pTopControl == NULL || pTopControl->getZ() < allControls[i]->getZ())
			{
				pTopControl = allControls[i];
			}
		}
	}
	return pTopControl;
}

void Panel::getAllControls(std::vector<Control*>* controls)
{
	//returns all controls in the panel including those in sub panels
	controls->clear();
	controls->insert(controls->end(), _controls.begin(), _controls.end());
	for (int i = 0; i < _controls.size(); i++)
	{
		vector<Control*> subControls;
		_controls[i]->getAllControls(&subControls);
		controls->insert(controls->end(), subControls.begin(), subControls.end());
	}
}


void Panel::mousePressed(int x, int y, bool isLeft)
{
	if (!isLeft)
		return;
	Control * pc = findTopControl(x, y);
	if (pc)
		pc->mousePressed(x, y, isLeft);
}

void Panel::keyDown(int keyCode, char charecter)
{
//to do - probably better to keep the focused control in the eventengine than to find the sub control here
}

void Panel::setZ(int zOrder) 
{
	_zOrder = zOrder;
	for (int i = 0; i < _controls.size(); i++)
	{
		_controls[i]->setZ(_zOrder+1);
	}
}
