
// MyMsg.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMyMsgApp:
// � ���������� ������� ������ ��. MyMsg.cpp
//

class CMyMsgApp : public CWinApp
{
public:
	CMyMsgApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMyMsgApp theApp;
