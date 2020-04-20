// NotePane.cpp : implementation file
//
#include "stdafx.h"
//#include "mnotes.h"
#include "NotesEnum.h"
#include "NotePane.h"
#include "MyCustomControl.h"
#include "PaintHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// CNotePane

//IMPLEMENT_DYNAMIC(CNotePane, CWnd)

CNotePane::CNotePane()
{

	m_note = Do;

	sounds[Do] = (LPCTSTR)DO_PATH;
	sounds[Re] = (LPCTSTR)RE_PATH;
	sounds[Mi] = (LPCTSTR)MI_PATH;
	sounds[Fa] = (LPCTSTR)FA_PATH;
	sounds[Sol] = (LPCTSTR)SOL_PATH;
		sounds[La] = (LPCTSTR)LA_PATH;
	sounds[Si] = (LPCTSTR)SI_PATH;
	sounds[Do2] = (LPCTSTR)DO2_PATH;
	sounds[Re2] = (LPCTSTR)RE2_PATH;
	sounds[Mi2] = (LPCTSTR)MI2_PATH;
	sounds[Fa2] = (LPCTSTR)FA2_PATH;
	sounds[Sol] = (LPCTSTR)SOL2_PATH;
		sounds[La2] = (LPCTSTR)LA2_PATH;
	sounds[Si2] = (LPCTSTR)SI2_PATH;


	RegisterWndClass();
	srand(time(0));
}

CNotePane::~CNotePane()
{
}

BEGIN_MESSAGE_MAP(CNotePane, CWnd)
	//{{AFX_MSG_MAP(CNotePane)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
//	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
void CNotePane::OnPaint()
{

	CPaintDC dc(this);
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	CRect rect;
	this->GetClientRect(&rect);
/*
	rect.left += 50;
	rect.bottom += 50;
	rect.top += 50;
	rect.right += 50;
*/
//	CPaintHelper::Message(dc, &rect);
	CPaintHelper::Lines(dc, &rect, 5);
	CPaintHelper::Note(dc, &rect, m_note);

}


void CNotePane::OnTimer(UINT_PTR idTimer){


	m_note = getNote();
	this->RedrawWindow();
	HRESULT res = PlaySound(sounds[m_note], NULL, SND_FILENAME);
}

void CNotePane::setOctaves(int octaves)
{
	m_octaves = octaves;
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

void CNotePane::setMode(const int mode)
{
	if (mode)
		generator = new TeacherGenerator(m_KeyNumber);
	else
		generator = new RandomNotesGenerator(m_KeyNumber);
}

Notes CNotePane::getNote(){
	
	return generator->getNote();
}

/*
BOOL CNotePane::OnEraseBkgnd(CDC *pDC){
	return CWnd::OnEraseBkgnd(pDC);
}
*/
BOOL CNotePane::RegisterWndClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, NOTE_PANEL_CLASS, &wndcls)))
	{
		// otherwise we need to register a new class
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInst;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = ::GetSysColorBrush(COLOR_WINDOW);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = NOTE_PANEL_CLASS;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}

	return TRUE;
}

int CNotePane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here


	return 0;
}


BOOL CNotePane::Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle){
//	UINT_PTR timer = SetTimer(1, 2000, NULL);
	return CWnd::Create(NOTE_PANEL_CLASS, _T(""), dwStyle, rect, pParentWnd, nID);

}

void CNotePane::OnLButtonDown(UINT nFlags, CPoint point)
{
}



// CNotePane message handlers


