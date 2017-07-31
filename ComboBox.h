#pragma once
#include "Panel.h"
class ComboBox :
	public Panel
{
private:
	void drawSelectedOption(Graphics & g);
	bool _isSelectionBoxOpened;
protected:
	int _selectedIndex;
	std::vector<std::string> _options;
	BorderDrawer* _pButtonBorderDrawer;

public:
	ComboBox(short left, short top, short width, size_t zOrder);
	void addOption(std::string option) { _options.push_back(option); };
	void getOptions(std::vector<std::string>* pOptions) { pOptions = &_options; };
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter);
	virtual bool canGetFocus() { return TRUE; };

	virtual ~ComboBox();
};

