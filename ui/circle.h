#include <wx/wx.h>

#ifndef CIRCLE
#define CIRCLE

class Circle : public wxPanel
{

public:
  Circle(wxWindow* parentWindow,int x,int y, int size);
  void setColour(wxColour color);
  
  void paintEvent(wxPaintEvent & evt);
  void paintNow();
  void render(wxDC& dc);
    
    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */
    
  DECLARE_EVENT_TABLE()

private:
  int x,y,size;
  wxColour color;
};
#endif // CIRCLE


