#pragma once
#include "Graphics.h"
#include <string>
using namespace std;


class BorderDrawer
{
public:
	BorderDrawer();
	virtual ~BorderDrawer();
	virtual void draw(Graphics& g, unsigned int l, unsigned int t, unsigned int w,unsigned int h) const = 0;
};

class NullBorderDrawer: public BorderDrawer
{
public:
	virtual void draw(Graphics& g, unsigned int l, unsigned int t, unsigned int w, unsigned int h) const;
};


class SingleBorderDrawer : public BorderDrawer
{
public:
	virtual void draw(Graphics& g, unsigned int l, unsigned int t, unsigned int w, unsigned int h) const;
};

class DoubleBorderDrawer : public BorderDrawer
{
public:
	virtual void draw(Graphics& g, unsigned int l, unsigned int t, unsigned int w, unsigned int h) const;
};
