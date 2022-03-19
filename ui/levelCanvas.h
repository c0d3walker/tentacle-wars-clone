#include <wx/wx.h>
#include "drawableComponent.h"
#include <vector>

#ifndef _LEVEL_CANVAS_
#define _LEVEL_CANVAS_
using namespace std;

class LevelCanvas : public wxPanel
{
  public:
    LevelCanvas(wxWindow* parent);
    void paintEvent(wxPaintEvent &event);
    void paintNow();
    void render(wxDC &dc);
    
    void setDrawableComponents(vector<DrawableComponent*>* components);

    DECLARE_EVENT_TABLE()
  
  private:
    vector<DrawableComponent*>* _components;    
};

#endif // _LEVEL_CANVAS_
