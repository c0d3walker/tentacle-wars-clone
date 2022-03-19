#include "levelCanvas.h"


BEGIN_EVENT_TABLE(LevelCanvas, wxPanel)
// EVT_MOTION(Circle::mouseMoved)
// EVT_LEFT_DOWN(Circle::mouseDown)
// EVT_LEFT_UP(Circle::mouseReleased)
// EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
// EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
// EVT_KEY_DOWN(BasicDrawPane::keyPressed)
// EVT_KEY_UP(BasicDrawPane::keyReleased)
// EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)

// catch paint events
EVT_PAINT(LevelCanvas::paintEvent)

END_EVENT_TABLE()

LevelCanvas::LevelCanvas(wxWindow* parent) : wxPanel(parent, -1, wxPoint(0,0), wxSize(500,300),wxTAB_TRAVERSAL,"level canvas")
{
  SetBackgroundColour(wxColor(50,50,50,255));
}

void LevelCanvas::paintEvent(wxPaintEvent &event)
{
  wxPaintDC dc(this);
  render(dc);
}

void LevelCanvas::paintNow()
{
  wxClientDC dc(this);
  render(dc);
}

void LevelCanvas::render(wxDC& dc)
{
  //dc.DrawText("1001",wxPoint(50,50));
  for(auto drawableElement = _components->begin(); drawableElement != _components->end(); drawableElement++){
    (*drawableElement)->drawComponent(dc);
  }
}

void LevelCanvas::setDrawableComponents(vector<DrawableComponent*>* components)
{
  _components = components;
}
