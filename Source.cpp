#include "stdafx.h"
#include "Graphics.h"

void xxmain()
{
	Graphics g = Graphics();
	g.moveTo(5, 21);
	g.write("hello");
	g.setBackground(Color::Red);
	g.setForeground(Color::Blue);
}
