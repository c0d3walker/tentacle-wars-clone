#include "application.h++"

bool Application::OnInit()
{
    _frame = new Frame();
    _frame->Show(true);
    return true;
}
int Application::OnExit()
{
    delete(_frame);
    return true;
}
Frame::Frame()
    : wxFrame(NULL, wxID_ANY, "Tentacle Wars")
{
  CreateStatusBar();
  SetStatusText("Status text");
}

