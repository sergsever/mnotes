
#pragma once

#include <map>
#include <tchar.h>

#ifndef NOTE_PANE_H
#define NOTE_PANE_H
#define NOTE_PANEL_CLASS _T("CNotePane")

// CNotePane

class CNotePane : public CWnd
{
//	DECLARE_DYNAMIC(CNotePane)

public:
	CNotePane();
	virtual ~CNotePane();
	void OnTimer(UINT_PTR idTimer);
	Notes m_note;
	void setOctaves(int octaves);

protected:
	int m_octaves = 1;
	int m_KeyNumber = 7;
	//{{AFX_MSG(MyCustomControl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void CNotePane::OnPaint();
	//}}AFX_MSG

	Notes NextNote();
	Notes RandNote();
	BOOL Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	const wchar_t *DO_PATH = L".\\sounds\\Do.wav";
	const wchar_t *RE_PATH = L".\\sounds\\Re.wav";
	const wchar_t *MI_PATH =	L".\\sounds\\Mi.wav";
	const wchar_t *FA_PATH =	L".\\sounds\\Fa.wav";
	const wchar_t *SOL_PATH =	L".\\sounds\\Sol.wav";
	const wchar_t *LA_PATH =	L".\\sounds\\La.wav";
	const wchar_t *SI_PATH =	L".\\sounds\\Si.wav";
	const wchar_t *DO2_PATH = L".\\sounds\\Do2.wav";
	const wchar_t *RE2_PATH = L".\\sounds\\Re2.wav";
	const wchar_t *MI2_PATH = L".\\sounds\\Mi2.wav";
	const wchar_t *FA2_PATH = L".\\sounds\\Fa2.wav";
	const wchar_t *SOL2_PATH = L".\\sounds\\Sol2.wav";
	const wchar_t *LA2_PATH = L".\\sounds\\La2.wav";
	const wchar_t *SI2_PATH = L".\\sounds\\Si2.wav";

	DECLARE_MESSAGE_MAP()
	std::map<Notes, LPCTSTR> sounds;
private:
	BOOL RegisterWndClass();


};

#endif

