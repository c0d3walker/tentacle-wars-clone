application: ui/application.c++ ui/application.h++
	g++ -o application ui/* `wx-config --cxxflags --libs`
