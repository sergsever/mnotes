#include "stdafx.h"
#include "Keyboard.h"

IMPLEMENT_DYNAMIC(CKeyboard, CWnd)

CKeyboard::CKeyboard(CPlayer &player) : m_player(player)
{
	m_player = player;
	RegisterWndClass();
}


BOOL CKeyboard::Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle)
{
	return CWnd::Create(KEYBOARD_CLASS, _T(""), dwStyle, rect, pParentWnd, nID);
}

BOOL CKeyboard::RegisterWndClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, KEYBOARD_CLASS, &wndcls)))
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
		wndcls.lpszClassName = KEYBOARD_CLASS;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}

	return TRUE;
}

void CKeyboard::OnLButtonUp(UINT flags, CPoint point)
{
	Notes n = GetNoteByXCoordinate(point.x);
	m_Note = n;
	m_player.Play(n);
}

void CKeyboard::setOctaves(int octaves)
{
	m_Octaves = octaves;
	switch (octaves)
	{
		case 1:
			m_KeyNumber = 7;
			break;
		case 2:
			m_KeyNumber = 14;
			break;

	}
}

CKeyboard::~CKeyboard()
{
}

BEGIN_MESSAGE_MAP(CKeyboard, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
//	ON_MESSAGE(WM_LBUTTONDOW, OnLButtonDown)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	END_MESSAGE_MAP()


void CKeyboard::OnMouseMove(UINT nFlags, CPoint point)
{
}

void CKeyboard::OnLButtonDblClk(UINT nFlags, CPoint point)
{
}



void CKeyboard::DrawKey(const int number, CPaintDC & dc)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	dc.SelectObject(brush);

/*
	CPoint points[2];
	points[0] = CPoint(LEFT_MARGIN + CKeyboard::KEY_WIDTCH *(number - 1), TOP_MARGIN);
	points[1] = CPoint(LEFT_MARGIN + CKeyboard::KEY_WIDTCH *(number - 1), TOP_MARGIN + HEIGHT);
	dc.Polyline(points, 2);
	*/
//	if (number == 0)
//		dc.Rectangle(0, TOP_MARGIN, LEFT_MARGIN + CKeyboard::KEY_WIDTCH, TOP_MARGIN + HEIGHT);
//	else
		dc.Rectangle(LEFT_MARGIN + CKeyboard::KEY_WIDTCH*(number - 1) , TOP_MARGIN, LEFT_MARGIN + CKeyboard::KEY_WIDTCH *(number - 1) + CKeyboard::KEY_WIDTCH , TOP_MARGIN + HEIGHT);
}

void CKeyboard::DrawKeys(CPaintDC& dc)
{
	for (int i = 1; i <= m_KeyNumber; ++i) {
		
		DrawKey(i, dc);

		if (isNeedBlackKey(i))
			DrawBlackKey(i, dc);
	}
	
}

BOOL CKeyboard::isNeedBlackKey(const int number)
{
	if (noblackset.find(number) != noblackset.end())
		return false;
	else
		return true;
}

void CKeyboard::DrawBlackKey(const int number, CPaintDC& dc)
{
/*
	CPoint points[2];
	points[0] = CPoint(LEFT_MARGIN + CKeyboard::KEY_WIDTCH *(number - 1) + CKeyboard::KEY_WIDTCH/2, TOP_MARGIN);
	points[1] = CPoint(LEFT_MARGIN + CKeyboard::KEY_WIDTCH/2 *(number) + CKeyboard::KEY_WIDTCH / 2, TOP_MARGIN + HEIGHT/2);
	CRect key(LEFT_MARGIN + CKeyboard::KEY_WIDTCH/2*(number1) + CKeyboard::KEY_WIDTCH / 2, TOP_MARGIN, LEFT_MARGIN + CKeyboard::KEY_WIDTCH *(number - 1) + CKeyboard::KEY_WIDTCH / 2, TOP_MARGIN + HEIGHT / 2);
	*/
	CBrush brush;
	brush.CreateSolidBrush(RGB(0, 0, 0));
	dc.SelectObject(brush);
		dc.Rectangle(LEFT_MARGIN + BLACK_MARGIN + CKeyboard::KEY_WIDTCH/2 *(number - 1) + CKeyboard::KEY_WIDTCH / 2*(number -1), TOP_MARGIN, LEFT_MARGIN + BLACK_MARGIN + CKeyboard::KEY_WIDTCH *(number - 1) + CKeyboard::KEY_WIDTCH / 2, TOP_MARGIN + HEIGHT / 2);//Polyline(points, 2);

}


void CKeyboard::OnPaint()
{
	CPaintDC dc(this);
	CPen pen(PS_SOLID, 0, RGB(255, 255, 255));
	CRect rect;
	this->GetClientRect(&rect);
//	WIDTCH = rect.right;
//	HEIGHT = rect.bottom;

	
	CPoint points[2];
	points[0] = CPoint(LEFT_MARGIN, TOP_MARGIN);
	points[1] = CPoint(LEFT_MARGIN + WIDTCH, TOP_MARGIN);
	dc.Polyline(points, 2);
	points[0] = CPoint(LEFT_MARGIN, TOP_MARGIN + HEIGHT);
	points[1] = CPoint(LEFT_MARGIN + WIDTCH, TOP_MARGIN + HEIGHT);
	dc.Polyline(points, 2);
	
	DrawKeys(dc);

}

void CKeyboard::OnTimer(UINT_PTR idTimer)
{
	this->RedrawWindow();
}

void CKeyboard::SetPlayer(CPlayer &player)
{
	m_player = player;
}


Notes CKeyboard::GetNoteByXCoordinate(const int x)
{
	for (int i = 1; i <= CKeyboard::KEY_NUMBER; ++i)
		if (x > LEFT_MARGIN + CKeyboard::KEY_WIDTCH*(i - 1) && x < LEFT_MARGIN + CKeyboard::KEY_WIDTCH*i)
			return static_cast<Notes>(i);
	return Si;
}

