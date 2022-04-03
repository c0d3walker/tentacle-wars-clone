#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#ifndef APPLICATION_SETUP
#define APPLICATION_SETUP

class Frame : public wxFrame
{
public:
    Frame();
};

class Application : public wxApp
{
public:
    virtual bool OnInit();

private:
    Frame* frame;
};

wxIMPLEMENT_APP(Application);



#endif // APPLICATION_SETUP


