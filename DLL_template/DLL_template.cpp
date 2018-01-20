// DLL_template.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "DLL_template.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CDLL_templateApp

BEGIN_MESSAGE_MAP(CDLL_templateApp, CWinApp)
END_MESSAGE_MAP()


// CDLL_templateApp 构造

CDLL_templateApp::CDLL_templateApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CDLL_templateApp 对象

CDLL_templateApp theApp;


// CDLL_templateApp 初始化

BOOL CDLL_templateApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

// 我的函数
int add(int a, int b)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return a+b;
}
//extern "C" 加了这个反而认识不了这个函数（在调用时是什么问题）
//定义输出库函数，以被MFC程序调用
__declspec(dllexport) int sub(int a, int b)
{
	//添加AFX_MANAGE_STATE宏，进行DLL模块状态资源的切换
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return a-b;
}