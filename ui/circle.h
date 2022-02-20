#include <wx/wx.h>

#ifndef CIRCLE
#define CIRCLE

class Circle : public wxPanel
{

public:
  Circle(wxWindow* parentWindow,int x,int y, int size);
  ~Circle();
  void setColour(wxColour color);
  void paintEvent(wxPaintEvent & evt);
  void paintNow();
  void render(wxDC& dc);
  void mouseMoved(wxMouseEvent& event);
  void mouseDown(wxMouseEvent& event);
  void mouseReleased(wxMouseEvent& event);


 //    void mouseWheelMoved(wxMouseEvent& event);
 //    void rightClick(wxMouseEvent& event);
 //    void mouseLeftWindow(wxMouseEvent& event);
 //    void keyPressed(wxKeyEvent& event);
 //    void keyReleased(wxKeyEvent& event);
    
  DECLARE_EVENT_TABLE()

private:
  bool isTargetingActive;
  int x,y,size;
  wxColour color;
  wxPoint* endPoint;
  void printPosition(wxMouseEvent& event);
};
#endif // CIRCLE


