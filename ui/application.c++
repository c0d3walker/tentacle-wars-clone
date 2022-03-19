#include "application.h++"
#include "levelCanvas.h"
#include <vector>
#include "circle.h"

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

vector<DrawableComponent*>* createLevel(){
  Circle* cell0=new Circle(60, 35, 60);
  cell0->setColour(wxColour(100,100,100,255));
  
  Circle* cell1=new Circle(125, 70, 85);
  cell1->setColour(wxColour(100, 100, 50, 255));

  vector<DrawableComponent*>* drawableComponents = new vector<DrawableComponent*>();
  drawableComponents -> push_back(cell0);
  drawableComponents -> push_back(cell1);
  return drawableComponents;
}

Frame::Frame()
    : wxFrame(NULL, wxID_ANY, "Tentacle Wars")
{
  SetBackgroundColour(wxColour(10,10,10,255));
 
  vector<DrawableComponent*>* drawableComponents = createLevel();

  wxBoxSizer* sizer=new wxBoxSizer(wxHORIZONTAL);
  LevelCanvas* canvas=new LevelCanvas(this);
  canvas->setDrawableComponents(drawableComponents);
  sizer->Add(canvas);
  SetSizerAndFit(sizer);


//Circle* cell0=new Circle(this, 800,30,80);
//cell0->setColour(wxColour(100,100,100,255));
//cell0->SetBackgroundColour(wxColour(200,100,100,255));

//Circle* cell1=new Circle(this, 50,50,60);
//cell1->setColour(wxColour(100,100,150,255));
//cell1->SetBackgroundColour(wxColour(50,200,100,255));


//  CreateStatusBar();
//  SetStatusText("Status text");
}
