
// mnotesDlg.h : header file
//

#pragma once

#include "resource.h"
#include "NotePane.h"
#include "Keyboard.h"
#include "CLed.h"
#include "CPlayer.h"

static const int PAUSE = 20000;


// CmnotesDlg dialog
class CmnotesDlg : public CDialog, CPlayer
{
// Construction
public:
	CmnotesDlg(int pause, CWnd* pParent = NULL);	// standard constructor
	void Play(Notes note);
	void setOctaves(int octaves);
	void setMode(const int mode);

// Dialog Data
	enum { IDD = IDD_MNOTES_DIALOG };

	protected:
	HICON m_hIcon;
	bool		m_Played;
	int			m_Pause;
	int         m_Octaves;
	int			m_TeacherMode;
	CNotePane	m_Pane;
	CKeyboard	m_Keyboard;
	CStatic		m_Good;
	CStatic		m_Bad;
	CLed		m_Led;
	unsigned int m_GoodCount;
	unsigned int m_BadCount;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	void CmnotesDlg::OnTimer(UINT time);


// Implementation


	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
