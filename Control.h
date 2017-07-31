#pragma once
#include "Graphics.h"
#include "BorderDrawer.h"
#include <vector>

using namespace std;

class Control
{
private :
	virtual void drawImpl(Graphics& g,unsigned int l, unsigned int t, size_t z) = 0;
protected:
	short _left;
	short _top;
	short _width;
	short _height;
	const BorderDrawer* _pBorderDrawer;
	int   _cursorIndex;
	size_t _zOrder;
	static Control* _controlInFocus;
public:
	Control(short left,short top, short width, short height, size_t zOrder = 0);
	static Control* getFocus() { return _controlInFocus; };
	static void setFocus(Control& control) { _controlInFocus = &control; };
	
	void setBorderDrawer(const BorderDrawer & borderDrawer) { _pBorderDrawer = &borderDrawer; };
	void draw(Graphics& g, int x, int y, size_t z);
	void draw(Graphics& g, size_t z);

	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual short getLeft() { return _left; };
	virtual short getTop() { return _top; };
	virtual short getWidth() { return _width; };
	virtual short getHeight() { return _height; };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
	virtual void  setLeft(short left) { _left = left; };
	virtual void  setTop(short top) { _top = top; };
	size_t getZ() { return _zOrder; };
	virtual void setZ(int zOrder) { _zOrder = zOrder; };
	~Control();
};

