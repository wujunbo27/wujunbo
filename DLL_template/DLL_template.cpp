// DLL_template.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "DLL_template.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CDLL_templateApp

BEGIN_MESSAGE_MAP(CDLL_templateApp, CWinApp)
END_MESSAGE_MAP()


// CDLL_templateApp ����

CDLL_templateApp::CDLL_templateApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDLL_templateApp ����

CDLL_templateApp theApp;


// CDLL_templateApp ��ʼ��

BOOL CDLL_templateApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

// �ҵĺ���
int add(int a, int b)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return a+b;
}
//extern "C" �������������ʶ��������������ڵ���ʱ��ʲô���⣩
//��������⺯�����Ա�MFC�������
__declspec(dllexport) int sub(int a, int b)
{
	//���AFX_MANAGE_STATE�꣬����DLLģ��״̬��Դ���л�
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return a-b;
}