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
    
    void setLevel(Level* level);

    DECLARE_EVENT_TABLE()
  
  private:
    Level* level;
};

#endif // _LEVEL_CANVAS_
