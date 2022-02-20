#include "circle.h"
#include "wx/dcbuffer.h"


BEGIN_EVENT_TABLE(Circle, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */

// catch paint events
EVT_PAINT(Circle::paintEvent)

END_EVENT_TABLE()

Circle::Circle(wxWindow* parentWindow,int x, int y, int size)
  : wxPanel(parentWindow,-1,wxPoint(x,y),wxSize(size,size),wxTAB_TRAVERSAL,"circle"){  
}


void Circle::setColour(wxColour colour){
  this->color=colour;
}

// some useful events
/*
 void BasicDrawPane::mouseMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseDown(wxMouseEvent& event) {}
 void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
 void BasicDrawPane::rightClick(wxMouseEvent& event) {}
 void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
 void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
 void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
 */


void Circle::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void Circle::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void Circle::render(wxDC&  dc)
{
    wxSize size=GetSize();
    int totalHeight = size.GetHeight() -2;
    int radius = totalHeight/2;
    wxPoint circleCenter = wxPoint(radius, radius);
    
    dc.SetBrush(color); // green filling
    dc.SetPen( wxPen(wxColor(200,200,200), 3 ) ); 
    dc.DrawCircle(circleCenter, radius );
    
    dc.DrawText(wxT("40"), circleCenter); 
}


