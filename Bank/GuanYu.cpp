// GuanYu.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "GuanYu.h"
#include "afxdialogex.h"


// GuanYu 对话框

IMPLEMENT_DYNAMIC(GuanYu, CDialogEx)

GuanYu::GuanYu(CWnd* pParent /*=NULL*/)
	: CDialogEx(GuanYu::IDD, pParent)
{

}

GuanYu::~GuanYu()
{
}

void GuanYu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GuanYu, CDialogEx)
END_MESSAGE_MAP()


// GuanYu 消息处理程序
