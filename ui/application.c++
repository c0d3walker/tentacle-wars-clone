#include "application.h++"
#include "circle.h"

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
SetBackgroundColour(wxColour(50,50,50,255));


Circle* cell0=new Circle(this, 50,400,300);
cell0->setColour(wxColour(100,100,100,255));
cell0->SetBackgroundColour(wxColour(200,100,100,255));

Circle* cell1=new Circle(this, 50,50,60);
cell1->setColour(wxColour(50,50,50,255));
cell1->SetBackgroundColour(wxColour(50,200,100,255));


//  CreateStatusBar();
//  SetStatusText("Status text");
}
