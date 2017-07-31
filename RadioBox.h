#pragma once
#include "Panel.h"
#include <vector>

class RadioBox :
        public panel
{
private:
    void drawSelectedOption(Graphics & g);
    bool _isSelectionBoxOpened;
protected:
    int _selectedIndex;
    std::vector<std::string> _options;
    BorderDrawer* _pButtonBorderDrawer;

public:
    RadioBox(int height, int width, vector<string> entries ,short left, short top, short width, size_t zOrder, int numofOptions);
    void addOption(std::string option) { _options.push_back(option); };
    void getOptions(std::vector<std::string>* pOptions) { pOptions = &_options; };
    virtual void mousePressed(int x, int y, bool isLeft);
    virtual void keyDown(int keyCode, char charecter);
    virtual bool canGetFocus() { return TRUE; };

    size_t GetSelectedIndex();
    void SetSelectedIndex(size_t index);


    virtual ~RadioBox();
};