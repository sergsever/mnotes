
// mnotes.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "mnotes.h"
#include "NotesEnum.h"
#include "NotePane.h"
#include "mnotesDlg.h"
//#include "CustomControlDlg.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmnotesApp

BEGIN_MESSAGE_MAP(CmnotesApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CmnotesApp construction

CmnotesApp::CmnotesApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CmnotesApp object

CmnotesApp theApp;


// CmnotesApp initialization

BOOL CmnotesApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


//	CShellManager *pShellManager = new CShellManager;

//	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

//	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	int pause = GetPrivateProfileInt(L"mnotes", L"pause", 0, L"C:\\mnotes\\mnotes.ini");
	int octaves = GetPrivateProfileInt(L"mnotes", L"octaves", 0, L"C:\\mnotes\\mnotes.ini");

	CmnotesDlg dlg(pause, NULL);
	dlg.setOctaves(octaves);
//	dlg.DoModal();
//	dlg.Create(IDD_MNOTES_DIALOG, NULL);
//  dlg.ShowWindow(SW_NORMAL);

	DWORD err = GetLastError();
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}


//	if (pShellManager != NULL)
//	{
//		delete pShellManager;
//	}

	return FALSE;
}

