#include<wx/wx.h>

#ifndef _DRAWABLE_COMPONENT_
#define _DRAWABLE_COMPONENT_

class DrawableComponent
{
  public:
     virtual void drawComponent(wxDC& dc) = 0;
};

#endif // _DRAWABLE_COMPONENT_
