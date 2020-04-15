
// mnotesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "mnotes.h"
#include "NotesEnum.h"
#include "Keyboard.h"
#include "mnotesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmnotesDlg dialog



CmnotesDlg::CmnotesDlg(int pause, CWnd* pParent)
	: CDialog(CmnotesDlg::IDD, pParent), m_Keyboard(*this)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Pause = pause;
//	Create(id, pParent);
}

void CmnotesDlg::Play(Notes note)
{
		m_Led.m_value = m_Pane.m_note == m_Keyboard.m_Note;
		if (m_Led.m_value)
			m_GoodCount++;
		else
			m_BadCount++;
		m_Led.RedrawWindow();
		UpdateData(false);
}

void CmnotesDlg::setOctaves(int octaves)
{
	m_Octaves = octaves;
	m_Keyboard.setOctaves(octaves);
	m_Pane.setOctaves(octaves);
}

void CmnotesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_Pane);
	DDX_Control(pDX, IDC_CUSTOM2, m_Keyboard);
	DDX_Control(pDX, IDC_CUSTOM3, m_Led);
	DDX_Control(pDX, IDC_STATIC_GOOD, m_Good);
	DDX_Control(pDX, IDC_STATIC_BAD, m_Bad);

	DDX_Text(pDX, IDC_STATIC_GOOD, m_GoodCount);
	DDX_Text(pDX, IDC_STATIC_BAD, m_BadCount);

/*
	wchar_t buff[16];

	_itow(m_GoodCount, buff, 10);

	m_Good.SetWindowText(buff);

	_itow(m_BadCount, buff, 10);
	m_Bad.SetWindowText(buff);
	*/


}

BEGIN_MESSAGE_MAP(CmnotesDlg, CDialog)
	ON_WM_SYSCOMMAND()
	
	ON_WM_PAINT()
	ON_WM_TIMER()
//	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CmnotesDlg message handlers

BOOL CmnotesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

/*
	m_NotePane.Create(this, CRect(50, 50, 250, 150), 1, WS_VISIBLE);
	m_Keyboard.Create(this, CRect(50, 152, 250, 250), 1, WS_VISIBLE);
*/
//	m_Keyboard.SetPlayCallBack(&this->Play);
	m_Pane.setOctaves(m_Octaves);
	m_Pane.m_note = Do;
	UINT_PTR timer = SetTimer(1, m_Pause, NULL);

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here


	return true;
	// return TRUE  unless you set the focus to a control
}

void CmnotesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon represented by handle m_hIcon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

void CmnotesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmnotesDlg::OnTimer(UINT time){
//	CmnotesDlg::RedrawWindow();
	m_Pane.OnTimer(time);
	m_Keyboard.OnTimer(time);
	m_Led.m_value = m_Pane.m_note == m_Keyboard.m_Note;
//	TRACE1("Compare:%d")
	m_Led.RedrawWindow();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmnotesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CmnotesDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
}

