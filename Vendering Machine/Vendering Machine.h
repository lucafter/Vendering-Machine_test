
// Vendering Machine.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVenderingMachineApp: 
// �йش����ʵ�֣������ Vendering Machine.cpp
//

class CVenderingMachineApp : public CWinApp
{
public:
	CVenderingMachineApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVenderingMachineApp theApp;