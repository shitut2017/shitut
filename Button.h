#pragma once
#include "Label.h"
#include "iListener.h"
class Button :
	public Label
{
protected:
	std::vector<IListener*> _listeners;
public:
	Button(short left, short top, short width,size_t zOrder);
	virtual ~Button();
	virtual void mousePressed(int x, int y, bool isLeft);
	void addListener(IListener * listener);
};

