// DLL_template.h : DLL_template DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDLL_templateApp
// �йش���ʵ�ֵ���Ϣ������� DLL_template.cpp
//

class CDLL_templateApp : public CWinApp
{
public:
	CDLL_templateApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
