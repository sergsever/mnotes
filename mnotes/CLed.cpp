#include "stdafx.h"
#include "CLed.h"

IMPLEMENT_DYNAMIC(CLed, CWnd)

CLed::CLed()
{
	RegisterWndClass();
}


CLed::~CLed()
{
}

BEGIN_MESSAGE_MAP(CLed, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL CLed::RegisterWndClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, LED_CLASS, &wndcls)))
	{
		// otherwise we need to register a new class
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInst;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = LED_CLASS;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}

	return TRUE;
}

void CLed::OnPaint()
{
	CPaintDC dc(this);
	CPen pen(PS_SOLID, 0, RGB(255, 255, 255));
	CRect rect;
	this->GetClientRect(&rect);
	CBrush brush;
	if (m_value)
		brush.CreateSolidBrush(RGB(0, 255, 0));
	else
		brush.CreateSolidBrush(RGB(255, 0, 0));

	dc.SelectObject(brush);
	dc.Rectangle(rect);


}
