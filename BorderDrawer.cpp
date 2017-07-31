#include "stdafx.h"
#include "BorderDrawer.h"


//BORDERS
const char* NULL_BD_CHAR = ".";

//BORDERS
const char* CORNER_TL = "\xDA";
const char* LINE_L			= "\xB3";
const char* CORNER_BL		= "\xC0";
const char* LINE_B			= "-";//"\xC4"
const char* CORNER_BR		= "\xD9";
const char* LINE_R			= "\xB3";
const char* CORNER_TR		= "\xBF";
const char* LINE_T			= "-";//"\xC4"

//DOUBLE BORDERS
//const char* CORNER_TL_D = "`";
const char* CORNER_TL_D		= "\xC9";
const char* LINE_L_D		= "\xBA";
const char* CORNER_BL_D		= "\xC8";
const char* LINE_B_D		= "=";// "\xCD"
const char* CORNER_BR_D		= "\xBC";
const char* LINE_R_D		= "\xBA";
//const char* CORNER_TR_D = "`";
const char* CORNER_TR_D		= "\xBB";
const char* LINE_T_D		= "=";// "\xCD"


BorderDrawer::BorderDrawer()
{
}

BorderDrawer::~BorderDrawer()
{
}

void NullBorderDrawer::draw(Graphics& g, unsigned int l, unsigned int t, unsigned int w, unsigned int h) const
{
	
	g.moveTo(l, t);
	g.write(NULL_BD_CHAR);
	for (int i = 0; i < w - 2; i++)
	{
		g.write(NULL_BD_CHAR);
	}
	g.write(NULL_BD_CHAR);
	for (int i = 1; i < h - 1; i++)
	{
		g.moveTo(l, t + i);
		g.write(NULL_BD_CHAR);
		g.moveTo(l + w - 1, t + i);
		g.write(NULL_BD_CHAR);
	}
	g.moveTo(l, t + h - 1);
	g.write(NULL_BD_CHAR);
	for (int i = 0; i < w - 2; i++)
	{
		g.write(NULL_BD_CHAR);
	}
	g.write(NULL_BD_CHAR);
	
}


void SingleBorderDrawer::draw(Graphics& g, unsigned int l, unsigned int t, unsigned int w, unsigned int h) const
{
	g.moveTo(l, t);
	g.write(CORNER_TL);
	for (int i = 0; i < w - 2; i++)
	{
		g.write(LINE_T);
	}
	g.write(CORNER_TR);
	for (int i = 1; i < h - 1; i++)
	{
		g.moveTo(l, t + i);
		g.write(LINE_L);
		g.moveTo(l + w-1, t + i);
		g.write(LINE_R);
	}
	g.moveTo(l, t + h - 1);
	g.write(CORNER_BL);
	for (int i = 0; i < w - 2; i++)
	{
		g.write(LINE_B);
	}
	g.write(CORNER_BR);
}


void DoubleBorderDrawer::draw(Graphics& g, unsigned int l, unsigned int t, unsigned int w, unsigned int h) const
{
	g.moveTo(l, t);
	g.write(CORNER_TL_D);
	for (int i = 0; i < w - 2; i++)
	{
		g.write(LINE_T_D);
	}
	g.write(CORNER_TR_D);
	for (int i = 1; i < h - 1; i++)
	{
		g.moveTo(l, t + i);
		g.write(LINE_L_D);
		g.moveTo(l + w - 1, t + i);
		g.write(LINE_R_D);
	}

	g.moveTo(l, t + h - 1);
	g.write(CORNER_BL_D);
	for (int i = 0; i < w - 2; i++)
	{
		g.write(LINE_B_D);
	}

	g.write(CORNER_BR_D);
}


void bdmain()
{
	Graphics g = Graphics();

	SingleBorderDrawer sbd;
	sbd.draw(g, 5, 10, 6, 9);

	DoubleBorderDrawer dbd;
	dbd.draw(g, 13, 12, 14, 5);

}