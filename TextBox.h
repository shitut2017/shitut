#pragma once
#include "Control.h"
class TextBox :
	public Control
{
protected:
	std::string _text;
	std::string _dummySpace;
	int			_maxLetters;
private:
	virtual void drawImpl(Graphics& g, unsigned int l, unsigned int t,size_t z);
	bool isValidTextChar(int KeyCode);
public:
	TextBox(short left, short top, short width, size_t zOrder);
	virtual ~TextBox();
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter);
	virtual void getAllControls(vector<Control*>* controls) { controls = NULL; };
	virtual bool canGetFocus() { return TRUE; };
	void setValue(string text);
};

