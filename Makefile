application: ui/application.c++ ui/application.h++ ui/circle.h ui/circle.c++
	g++ -o application ui/* `wx-config --cxxflags --libs`

code: ui/*
	g++ -E ui/* `wx-config --cxxflags --libs` > uiCode
