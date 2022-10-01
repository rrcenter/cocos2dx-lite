/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "main.h"
#include "SimulatorWin.h"
#include <shellapi.h>

#include "cocos2d.h"
#include "wx/wx.h"
#include "wx/cmdline.h"
USING_NS_CC;

cocos2d::Size getWinSize()
{
	int width = 0;
	int height = 0;
	wxDisplaySize(&width, &height);
	return cocos2d::Size(width, height);
}

class MyApp : public wxApp
{
public:
	virtual bool OnInit() override;
	void OnBtnClick(wxCommandEvent &WXUNUSED(event));
	void OnTimer(wxTimerEvent&)
	{
		if (_logFp == NULL)
		{
			return;
		}
		clearerr(_logFp);
		while (!feof(_logFp))
		{
			char buf[1024] = { '\0' };
			fgets(buf, 1024, _logFp);
			if (strlen(buf))
			{
				_textView->AppendText(buf);
			}
		}

	}
private:
	std::string logPath = "d:\\test.txt";
	wxTimer   m_timer;
	static const int timerInterval = 100; // ms
	FILE *_logFp = NULL;
	wxTextCtrl* _textView;
};
DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)


bool MyApp::OnInit()
{
	freopen(logPath.c_str(), "w", stdout);
	freopen(logPath.c_str(), "a+", stderr);

	_logFp = fopen(logPath.c_str(), "r");

	// call default behaviour (mandatory)
	//if (!wxApp::OnInit())
	//	return false;

	int width = 0;
	int height = 0;
	wxDisplaySize(&width, &height);
	int consoleHeight = 480;
	int consoleWidth = 640;
	int consolePosY = height - consoleHeight - 50;

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxFrame* frame = new wxFrame(NULL, wxID_ANY, wxT("LogView"));
	frame->SetSize(50, consolePosY, consoleWidth, consoleHeight);
	//wxPanel* panel = new wxPanel(frame, wxID_ANY);
	frame->SetSizer(mainSizer);

	wxButton* button = new wxButton(frame, wxID_EXIT, wxT("Test"), wxPoint(20, 20));
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyApp::OnBtnClick));
	button->SetFocus();
	mainSizer->Add(button, 0, wxEXPAND | wxALL, 5);

	wxTextCtrl* text = new wxTextCtrl(frame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
		0 | wxTE_PROCESS_ENTER | wxTE_MULTILINE);
	_textView = text;
	_textView->SetEditable(false);
	mainSizer->Add(text, 1, wxEXPAND | wxALL, 5);
	//wxStreamToTextRedirector redirect(text);
	//cout << "Hello, text!" << endl;

	frame->Show();

	m_timer.Bind(wxEVT_TIMER, &MyApp::OnTimer, this);
	m_timer.Start(timerInterval);



	//return true;
	auto simulator = SimulatorWin::getInstance();
	return simulator->run();

	AppDelegate app;
	return Application::getInstance()->run();
}

void MyApp::OnBtnClick(wxCommandEvent& WXUNUSED(event))
{
	CCLOG("%s", __FUNCTION__);
	auto label = Label::createWithSystemFont("test", "arial", 24);
	Vec2 pos = Vec2(CCRANDOM_0_1() * 200, CCRANDOM_0_1() * 200);
	label->setPosition(pos);
	Director::sharedDirector()->getRunningScene()->addChild(label);
}

// wx: never invoke bellow codes
int WINAPI _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
    auto simulator = SimulatorWin::getInstance();
    return simulator->run();
}
