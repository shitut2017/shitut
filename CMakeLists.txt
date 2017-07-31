cmake_minimum_required(VERSION 3.8)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ActionListeners.cpp BorderDrawer.cpp BorderDrawer.h Button.cpp Button.h classes.cpp ComboBox.cpp ComboBox.h ConsoleApplication2.cpp Control.cpp Control.h controls.cpp definitions.h EventEngine.cpp EventEngine.h Graphics.cpp Graphics.h IListener.h KickAss.cpp Label.cpp Label.h  NumericBox.cpp NumericBox.h Panel.cpp Panel.h RadioBox.cpp RadioBox.h Source.cpp Source.cpp stdafx.cpp stdafx.h targetver.h TextBox.cpp TextBox.h MessageBox.cpp MessageBox.h)
add_executable(untitled1 ${SOURCE_FILES})