#pragma once
#include "Panel.h"
class NumericBox : public Panel
{
	
private:
	void updateLabelValue();
protected:
	int _minVal;
	int _maxVal;
	int _value;
	BorderDrawer* _pButtonBorderDrawer;
public:
	NumericBox(short left, short top, short width, int minVal, int maxVal, size_t zOrder);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual ~NumericBox();
};

