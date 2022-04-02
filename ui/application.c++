#include "application.h++"
#include "levelCanvas.h"
#include <vector>
#include "circle.h"
#include "level.h"
using namespace std;

bool Application::OnInit()
{
    _frame = new Frame();
    _frame->Show(true);
    return true;
}
int Application::OnExit()
{
//    delete(_frame);
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
