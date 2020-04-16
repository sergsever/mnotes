#pragma once
#include <set>
#include "NotesEnum.h"
#include "CPlayer.h"


#define KEYBOARD_CLASS _T("CKeyboard")
typedef void(play)(Notes note);

const static int LEFT_MARGIN = 50;
const static int TOP_MARGIN = 1;
const static int WIDTCH = 364;
const static int HEIGHT = 102;

class CKeyboard : public CWnd
{
	DECLARE_DYNAMIC(CKeyboard)

public:
	const static int KEY_NUMBER = 14;
	const static int BLACK_KEY_NUMBER = KEY_NUMBER/7*5;
	const static int KEY_WIDTCH = WIDTCH / KEY_NUMBER;
	const static int BLACK_MARGIN = -4;//-1 * KEY_WIDTCH / 3;
				 Notes m_Note;
	CKeyboard(CPlayer &player );
	BOOL CKeyboard::Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle);
	BOOL CKeyboard::RegisterWndClass();
	void CKeyboard::OnPaint();
	void CKeyboard::OnTimer(UINT_PTR idTimer);
	void CKeyboard::SetPlayer(CPlayer &player);
	void CKeyboard::setOctaves(int octaves);
	~CKeyboard();
protected:
	int m_KeyNumber;
	int m_Octaves;
	void CKeyboard::Rectangle(CPaintDC & dc, int x1, int y1, int x2, int y2);
	void CKeyboard::DrawKey(const int number, CPaintDC& dc);
	void CKeyboard::DrawKeys(CPaintDC& dc);
	void CKeyboard::DrawBlackKey(const int number, CPaintDC& dc);
	std::set<int> noblackset = {1, 4, 8, 11, 15};
	CPlayer &m_player;
	BOOL isNeedBlackKey(const int number);
	Notes CKeyboard::GetNoteByXCoordinate(const int x);
	afx_msg void OnLButtonUp(UINT flags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);



	DECLARE_MESSAGE_MAP()

};

