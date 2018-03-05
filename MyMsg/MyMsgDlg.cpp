
// MyMsgDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MyMsg.h"
#include "MyMsgDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMyMsgDlg



CMyMsgDlg::CMyMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYMSG_DIALOG, pParent)
	, m_ResultsEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULTS_EDIT, m_ResultsEdit);
}

BEGIN_MESSAGE_MAP(CMyMsgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CMyMsgDlg::OnClickedExitButton)
	ON_BN_CLICKED(IDC_OKCANCEL_BUTTON2, &CMyMsgDlg::OnClickedOkcancelButton)
	ON_BN_CLICKED(IDC_YESNOCANCEL_BUTTON, &CMyMsgDlg::OnClickedYesnocancelButton)
	ON_BN_CLICKED(IDC_RETRYCANCEL_BUTTON, &CMyMsgDlg::OnClickedRetrycancelButton)
	ON_BN_CLICKED(IDC_YESNO_BUTTON2, &CMyMsgDlg::OnClickedYesnoButton)
END_MESSAGE_MAP()


// ����������� ��������� CMyMsgDlg

BOOL CMyMsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
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

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMyMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMyMsgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMyMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyMsgDlg::OnClickedExitButton()
{
	// TODO: �������� ���� ��� ����������� �����������

	int iResults;
	iResults = MessageBox((LPCTSTR)"You want to exit.",
		(LPCTSTR)"I am the second parameter of the MessageBox function",
		MB_YESNO + MB_ICONQUESTION);

	if (iResults == IDYES)
		OnOK();
}


void CMyMsgDlg::OnClickedOkcancelButton()
{
	// TODO: �������� ���� ��� ����������� �����������

	int iResults;
	iResults = MessageBox((LPCTSTR)"You want Ok and Cancel buttons.",
		(LPCTSTR)"I am the second parametr of the MessageBox function",
		MB_OKCANCEL + MB_ICONSTOP);
	if (iResults == IDOK)
	{
		m_ResultsEdit = "You Clicked the Ok button";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_ResultsEdit = "You clicked on the Cancel button";
		UpdateData(FALSE);
	}
}


void CMyMsgDlg::OnClickedYesnocancelButton()
{
	// TODO: �������� ���� ��� ����������� �����������

	int iResults;
	iResults = MessageBox((LPCTSTR)"You want Yes, No and Cancel buttons.",
		(LPCTSTR)"I am the second parameter of the MessageBox function",
		MB_YESNOCANCEL + MB_ICONINFORMATION);

	if (iResults == IDYES)
	{
		m_ResultsEdit = "You clicked on the Yes button.";
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_ResultsEdit = "You clicked on the No button";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_ResultsEdit = "You clicked on the Cancel button.";
		UpdateData(FALSE);
	}
}


void CMyMsgDlg::OnClickedRetrycancelButton()
{
	// TODO: �������� ���� ��� ����������� �����������

	int iResults;
	iResults = MessageBox((LPCTSTR)"You want Retry and Cancel buttons.",
		(LPCTSTR)"I am the second parameter of the MessageBox function",
		MB_RETRYCANCEL + MB_ICONQUESTION);

	if (iResults == IDRETRY)
	{
		m_ResultsEdit = "You clicked on the Retry button.";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_ResultsEdit = "You clicked on the Cancel button.";
		UpdateData(FALSE);
	}
}


void CMyMsgDlg::OnClickedYesnoButton()
{
	// TODO: �������� ���� ��� ����������� �����������

	int iResults;
	iResults = MessageBox((LPCTSTR)"You want Yes and No buttons.",
		(LPCTSTR)"I am the second parameter of the MessageBox function",
		MB_YESNO + MB_ICONEXCLAMATION);

	if (iResults == IDYES)
	{
		m_ResultsEdit = "You clicked on the YES button.";
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_ResultsEdit = "You clicked on the NO button.";
		UpdateData(FALSE);
	}
}
