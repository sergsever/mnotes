#pragma once
#include <afxwin.h>
#define LED_CLASS _T("CLed")

class CLed :
	public CWnd
{
	DECLARE_DYNAMIC(CLed)
public:
	CLed();
	BOOL m_value;
	virtual ~CLed();
	BOOL CLed::RegisterWndClass();

protected:
	void CLed::OnPaint();
	DECLARE_MESSAGE_MAP()

};

