#include "application.h++"

int main(int argn,char** argv)
{
  Application();
}



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

}

