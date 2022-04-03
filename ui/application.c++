#include "application.h++"
#include "levelCanvas.h"
using namespace std;

bool Application::OnInit()
{
    frame = new Frame();
    frame->Show(true);
    return true;
}


Frame::Frame()
    : wxFrame(NULL, wxID_ANY, "Tentacle Wars")
{
  SetBackgroundColour(wxColour(10,10,10,255));

  Level* level = new Level();
  level->create();
  wxBoxSizer* sizer=new wxBoxSizer(wxHORIZONTAL);
  LevelCanvas* canvas=new LevelCanvas(this);
  canvas->setLevel(level);
  sizer->Add(canvas);
  SetSizerAndFit(sizer);

//  CreateStatusBar();
//  SetStatusText("Status text");
}



