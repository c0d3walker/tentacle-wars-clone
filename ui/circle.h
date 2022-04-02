#include "drawableComponent.h"
#include "player.h"

#ifndef _CELL_
#define _CELL_

class Circle : public DrawableComponent
{

public:
  Circle(int x,int y, int size);
  ~Circle();
//  void setColour(wxColour color);
  void setPlayer(Player* player);
  void drawComponent(wxDC& dc);
  //void paintEvent(wxPaintEvent & evt);
  //void paintNow();
  //void render(wxDC& dc);
  //void mouseMoved(wxMouseEvent& event);
  //void mouseDown(wxMouseEvent& event);
  //void mouseReleased(wxMouseEvent& event);


 //    void mouseWheelMoved(wxMouseEvent& event);
 //    void rightClick(wxMouseEvent& event);
 //    void mouseLeftWindow(wxMouseEvent& event);
 //    void keyPressed(wxKeyEvent& event);
 //    void keyReleased(wxKeyEvent& event);
    
//  DECLARE_EVENT_TABLE()

private:
//  bool isTargetingActive;
  int x,y,size;
  wxColour color;
  Player* player;
//  wxPoint* endPoint;
//  void printPosition(wxMouseEvent& event);
};
#endif // CELL


