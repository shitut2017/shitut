#pragma once
#include "Control.h"
#include <vector>
class Panel : public Control
{
private:
	virtual void drawImpl(Graphics& g, unsigned int l, unsigned int t, size_t z);
	Control* findTopControl(int x, int y);
protected:
	std::vector<Control*> _controls;
public:
	Panel(short left, short top, short width, short height,size_t zOrder);
	virtual void getAllControls(std::vector<Control*>* controls) ;
	virtual bool canGetFocus() { return FALSE; };
	virtual void addControl(Control* pControl);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter);
	virtual void setZ(int zOrder);

	virtual ~Panel();
};

