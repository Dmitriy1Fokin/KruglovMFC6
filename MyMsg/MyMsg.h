
// MyMsg.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMyMsgApp:
// О реализации данного класса см. MyMsg.cpp
//

class CMyMsgApp : public CWinApp
{
public:
	CMyMsgApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMyMsgApp theApp;
