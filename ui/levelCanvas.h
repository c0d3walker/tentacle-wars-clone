#include <wx/wx.h>
#include "drawableComponent.h"
#include "level.h"
#include <vector>

#ifndef _LEVEL_CANVAS_
#define _LEVEL_CANVAS_
using namespace std;

class LevelCanvas : public wxPanel
{
  public:
    LevelCanvas(wxWindow* parent);
    ~LevelCanvas();
    void paintEvent(wxPaintEvent &event);
    void paintNow();
    void render(wxDC &dc);

    void mouseDown(wxMouseEvent &event);
    void mouseReleased(wxMouseEvent &event);
    void mouseMoved(wxMouseEvent &event);

    void setLevel(Level* level);

    DECLARE_EVENT_TABLE()
  
  private:
    Level* level;
    wxPoint* mouseDownPoint;
    wxPoint* currentMousePosition;
    wxPoint* oldMousePosition;

    void setCurrentMouseLocation(wxMouseEvent &event, wxPoint* point);
    void drawTargetingLine(wxDC& dc);
    void removeTargetingLine(wxDC& dc);
};

#endif // _LEVEL_CANVAS_
