#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include "ActionListeners.cpp"

using namespace std;

class ILT {
public:
	ILT() {};
	virtual void printHello() = 0;
};

class CLT : public ILT {
public:

	void printHello(){
		cout << "hello world" << endl;
	}
};

class DLT : public ILT {
protected:
	ILT& inner;	
public:
	DLT(ILT& _inner) : ILT(), inner(_inner) {};
};

class RLT : public DLT {
public:
	RLT(ILT& a) : DLT(a) {};
	void printHello() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csri;
		GetConsoleScreenBufferInfo(h, &csri);
		WORD oldColors = csri.wAttributes;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		DLT::inner.printHello();
		SetConsoleTextAttribute(h, oldColors);

	}
};


class ICompositeLT : public ILT {
	vector <ILT*> children;
protected:
	ICompositeLT() : ILT() {};
public:
	void printHello() {
		for each (ILT* ilt in children)
		{
			ilt->printHello();
		}
	}

	void AddChild(ILT* child) {
		children.push_back(child);
	}
};

class BorderCompositeLT : public ICompositeLT {
public:
	BorderCompositeLT() : ICompositeLT() {};
	void printHello() {
		cout << "--------------" << endl;
		ICompositeLT::printHello();
		cout << "--------------" << endl;
	}

};

void ggmain() {


	
	ILT& c = CLT();
	ILT& r = RLT(c);
	
	c.printHello(); //print hello without color;
	r.printHello(); //print hello with color;
	c.printHello(); //print hello without color;
	

	ILT& comp = BorderCompositeLT();
	((BorderCompositeLT&)comp).AddChild(&c);
	((BorderCompositeLT&)comp).AddChild(&r);
	comp.printHello();
	
	//init time bombs !

	//IListener& lstn = TimerListener();
	//TimerAction iap = TimerAction(lstn);
	//iap.initBomb();
	
}