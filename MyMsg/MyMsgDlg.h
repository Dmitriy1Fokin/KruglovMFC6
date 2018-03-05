
// MyMsgDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CMyMsgDlg
class CMyMsgDlg : public CDialogEx
{
// ��������
public:
	CMyMsgDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMSG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_ResultsEdit;
	afx_msg void OnClickedExitButton();
	afx_msg void OnClickedOkcancelButton();
	afx_msg void OnClickedYesnocancelButton();
	afx_msg void OnClickedRetrycancelButton();
	afx_msg void OnClickedYesnoButton();
};
