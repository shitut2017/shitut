#include "stdafx.h"
#include "Graphics.h"
#include "Control.h"
#include "TextBox.h"
#include "Label.h"
#include "Panel.h"
#include "EventEngine.h"
#include "BorderDrawer.h"
#include "Button.h"
#include "NumericBox.h"


using namespace std;

int  main()
{
	Graphics g;
	DoubleBorderDrawer bdDbl;
	SingleBorderDrawer bdSngl;
	NullBorderDrawer bdNull;
	/*
	//label test
	//==========

	Label lbl1(1, 1, 10,1);
	lbl1.setBorderDrawer(bd);
	lbl1.setValue("hello");
	//lbl1.draw(g, 0, 0, 0);

	Label lbl2(11, 12, 14,1);
	lbl2.setBorderDrawer(bd2);
	lbl2.setValue("CYA BABY");
	//lbl2.draw(g, 0, 0, 0);
	
	Button btn1(3,3,10,1);
	btn1.setValue("click me");
	btn1.setBorderDrawer(bd2);
	
	*/

	/*
	//test text box
	//=============
	TextBox tbx1(5, 3, 10);
	tbx1.setBorderDrawer(bd);
	tbx1.setValue("hello");
	tbx1.draw(g, 0, 0, 0);

	tbx1.mousePressed(0, 0, true);
	Sleep(1000);
	tbx1.mousePressed(2, 0, true);
	Sleep(1000);
	tbx1.mousePressed(5, 1, true);
	Sleep(1000);
	tbx1.keyDown(70, 'G');
	Sleep(1000);
	tbx1.keyDown(71, 'H');
	Sleep(1000);
	tbx1.mousePressed(2, 1, true);
	Sleep(1000);
	tbx1.keyDown(72, 'I');
	Sleep(1000);
	tbx1.keyDown(72, 'I');
	Sleep(1000);
	tbx1.keyDown(72, 'I');
	Sleep(1000);
	tbx1.keyDown(72, 'I');
	Sleep(1000);
	tbx1.keyDown(46, ' ');
	Sleep(1000);
	tbx1.keyDown(46, ' ');
	Sleep(1000);
	tbx1.keyDown(8, ' ');
	Sleep(1000);

	tbx1.setValue("BYE BYE BYE");
	Sleep(1000);
	tbx1.draw(g, 0, 0, 0);
	Sleep(1000);
	*/

	TextBox tbx1(20, 0, 14, 1);
	tbx1.setBorderDrawer(bdSngl);
	tbx1.setValue("hello");

	//Panel test:
	//===========
	Label lbl1(0, 5, 10, 1);
	lbl1.setBorderDrawer(bdDbl);
	lbl1.setValue("hello");
	//lbl1.draw(g, 0, 0, 0);
/*
	Label lbl2(0, 10, 14, 1);
	lbl2.setBorderDrawer(bdNull);
	lbl2.setValue("CYA BABY");

	Button btn1(25, 10, 10, 1);
	btn1.setValue("click me");
	btn1.setBorderDrawer(bdSngl);
	TimerListener timeListener;
	btn1.addListener(&timeListener);

	//numericBox1.draw(g, 0, 0, 0);
	Button b(0,7,5,0);
	b.setBorderDrawer(bdSngl);
	*/
	NumericBox numericBox1(3, 3, 11, 10, 100, 1);

	Panel pnl(0, 0, 80, 23,0);
	pnl.setBorderDrawer(bdDbl);
	pnl.addControl(&lbl1);
	pnl.addControl(&tbx1);
	//pnl.addControl(&lbl2);
	//pnl.addControl(&btn1);
	pnl.addControl(&numericBox1);
	pnl.draw(g, 0);
	//Event engine
	//EventEngine ee;
	//ee.run(pnl);
	/*

	numericBox1.mousePressed(10, 0, true);
	Sleep(1000);
	numericBox1.mousePressed(6, 0, true);
	Sleep(1000);
	numericBox1.mousePressed(0, 0, true);
	Sleep(1000);
	numericBox1.mousePressed(0, 0, true);
	Sleep(1000);
	numericBox1.mousePressed(0, 0, true);
	Sleep(1000);
	numericBox1.mousePressed(0, 0, true);
	Sleep(1000);
	numericBox1.mousePressed(0, 0, true);
	Sleep(1000);



	lbl2.mousePressed(0, 0, true);
	Sleep(1000);
	lbl1.mousePressed(0, 0, true);
	Sleep(1000);

	lbl2.keyDown(70, 'G');
	Sleep(1000);
	lbl1.keyDown(70, 'G');
	Sleep(1000);
	*/
	//btn1.mousePressed(0, 0, true);
	//Sleep(5000);
//
	int x;
	cin >> x;
	return 0;
}
