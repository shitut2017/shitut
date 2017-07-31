#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>


class IListener {
public:
	virtual void action() = 0;
};

class IActionProvider {
	IListener& lstn;
protected:
	IActionProvider(IListener& _lstn) : lstn(_lstn) {};
public:
	void action() {
		lstn.action();
	}
};

class TimerListener : public IListener {
public:
	TimerListener() : IListener() {};
	void action() {
		std::cout << "timer expired, you're dead !" << std::endl;
	}
};

class TimerAction : public IActionProvider {
public:
	TimerAction(IListener& lstn) : IActionProvider(lstn) {};
	void initBomb() {
		for (int i = 0; i < 1000; i++) {
			std::cout << i << std::endl;
		}
		std::cout << "boom ";
		IActionProvider::action();
	}

};