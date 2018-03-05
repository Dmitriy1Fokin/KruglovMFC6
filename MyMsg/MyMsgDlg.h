
// MyMsgDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CMyMsgDlg
class CMyMsgDlg : public CDialogEx
{
// Создание
public:
	CMyMsgDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMSG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
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
