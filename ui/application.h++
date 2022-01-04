// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class Frame : public wxFrame
{
public:
    Frame();
};

class Application : public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
private:
    Frame* _frame;
};


