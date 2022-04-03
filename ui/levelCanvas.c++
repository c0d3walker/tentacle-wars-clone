#include "levelCanvas.h"


BEGIN_EVENT_TABLE(LevelCanvas, wxPanel)
  EVT_MOTION(LevelCanvas::mouseMoved)
  EVT_LEFT_DOWN(LevelCanvas::mouseDown)
  EVT_LEFT_UP(LevelCanvas::mouseReleased)
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
  SetBackgroundColour(wxColour(50,50,50,255));
  mouseDownPoint = NULL;
  currentMousePosition = NULL;
  oldMousePosition = NULL;
}

LevelCanvas::~LevelCanvas()
{
  delete level;
}

void LevelCanvas::mouseDown(wxMouseEvent &event)
{
  mouseDownPoint = new wxPoint();
  setCurrentMouseLocation(event, mouseDownPoint);
}

void LevelCanvas::mouseReleased(wxMouseEvent &event)
{
  delete mouseDownPoint;
  mouseDownPoint = NULL;
  delete currentMousePosition;
  currentMousePosition = NULL;
  delete oldMousePosition;
  oldMousePosition = NULL;
  paintNow();
}

void LevelCanvas::mouseMoved(wxMouseEvent &event)
{
  delete oldMousePosition;
  oldMousePosition = currentMousePosition;
  currentMousePosition = new wxPoint();
  setCurrentMouseLocation(event, currentMousePosition);
  paintNow();
}

void LevelCanvas::setCurrentMouseLocation(wxMouseEvent &event,wxPoint* mousePoint)
{
  wxClientDC dc(this);
  wxPoint mousePosition = event.GetLogicalPosition(dc);
  mousePoint->x = mousePosition.x;
  mousePoint->y = mousePosition.y;
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
//  removeTargetingLine(dc);
  dc.SetBrush(wxBrush(this->GetBackgroundColour()));
  wxSize size = this->GetSize();
  dc.DrawRectangle(wxPoint(0,0), size);
  
  auto _components = level->getDrawableComponents();
  for(auto drawableElement = _components->begin(); drawableElement != _components->end(); drawableElement++){
    (*drawableElement)->drawComponent(dc);
  }
  drawTargetingLine(dc);
}

void LevelCanvas::removeTargetingLine(wxDC& dc)
{
  if(mouseDownPoint != NULL && oldMousePosition != NULL)
  {
    dc.SetPen(wxPen(wxColour(50,50,50,255)));
    dc.DrawLine(*mouseDownPoint, *oldMousePosition);
  }
}

void LevelCanvas::drawTargetingLine(wxDC& dc)
{
  if(mouseDownPoint != NULL && currentMousePosition != NULL)
  {
    dc.SetPen(wxPen(wxColor(255,255,0,255)));
    dc.DrawLine(*mouseDownPoint, *currentMousePosition);
  }
}

void LevelCanvas::setLevel(Level* level)
{
  this->level=level;
}
