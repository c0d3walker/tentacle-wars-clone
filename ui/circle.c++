#include "circle.h"
#include "wx/dcbuffer.h"
#include <string>
#include <iostream>
using namespace std;
/*
BEGIN_EVENT_TABLE(Circle, wxPanel)
 EVT_MOTION(Circle::mouseMoved)
 EVT_LEFT_DOWN(Circle::mouseDown)
 EVT_LEFT_UP(Circle::mouseReleased)
// EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
// EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
// EVT_KEY_DOWN(BasicDrawPane::keyPressed)
// EVT_KEY_UP(BasicDrawPane::keyReleased)
// EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)

// catch paint events
EVT_PAINT(Circle::paintEvent)

END_EVENT_TABLE()

Circle::Circle(wxWindow* parentWindow,int x, int y, int size)
  : wxPanel(parentWindow,-1,wxPoint(x,y),wxSize(size,size),wxTAB_TRAVERSAL,"circle"){  
  isTargetingActive=false;
  endPoint=NULL;
}

Circle::~Circle()
{
  free(endPoint);
}*/

Circle::Circle(int x, int y, int size)
{
  this->size=size;
  this->x=x;
  this->y=y;
}

void Circle::setPlayer(Player* player)
{
  this->player=player;
}

/*void Circle::setColour(wxColour colour){
  this->color=colour;
}*/
/*
void Circle::printPosition(wxMouseEvent& event)
{
  wxClientDC dc(this);
  int x,y;
  event.GetPosition(&x, &y);
  cout << "["<<x<<"|"<<y<<"]"<<endl;
  endPoint = new wxPoint(x,y);
}

void Circle::mouseMoved(wxMouseEvent& event)
{
  if(isTargetingActive)
  {
    printf("move");
    printPosition(event);
    paintNow();
  }
}

void Circle::mouseDown(wxMouseEvent& event)
{
  printf("down");
  printPosition(event);
  isTargetingActive=true;
}

void Circle::mouseReleased(wxMouseEvent& event)
{
  printf("up");
  isTargetingActive=false;
  printPosition(event);
  endPoint=NULL;
  paintNow();
}


// void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
// void BasicDrawPane::rightClick(wxMouseEvent& event) {}
// void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
// void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
// void BasicDrawPane::keyReleased(wxKeyEvent& event) {}


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

*/
void Circle::drawComponent(wxDC& dc)
{
    int totalHeight = size -4;
    int radius = totalHeight/2;
    wxPoint circleCenter = wxPoint(radius+1+x, radius+1+y);
   
    wxColour color=player==NULL?wxColour(150,150,150,255):player->getColor();

    dc.SetBrush(color); 
    dc.SetPen( wxPen(wxColor(200,200,200), 3 ) ); 
    dc.DrawCircle(circleCenter, radius );
    
    wxFont font("arial");
    wxFont boldFont = font.Bold();
    wxSize letterSize =  boldFont.GetPixelSize();
    dc.SetFont(font.Bold());
    wxString text("40");
    int length=text.length();
    
    dc.DrawText(to_string(size), wxPoint(circleCenter.x-(length*letterSize.x)/2,circleCenter.y-letterSize.y/2)); 

}
