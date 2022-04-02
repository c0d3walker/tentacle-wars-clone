application: ui/application.c++ ui/application.h++ ui/circle.h ui/circle.c++ ui/levelCanvas.h ui/levelCanvas.c++ ui/drawableComponent.h ui/level.c++ ui/level.h ui/player.c++ ui/player.h
	g++ -o application ui/* `wx-config --cxxflags --libs`

model: model/level.h model/level.c++
	g++ -c ./model/* -o model.o

code: ui/*
	g++ -E ui/* `wx-config --cxxflags --libs` > uiCode
