// ZhuJieMian_dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "ZhuJieMian_dlg.h"
#include "afxdialogex.h"
#include "AddCustomer.h"
#include "GuanYu.h"
#include "BanLiKa.h"

// ZhuJieMian_dlg 对话框

IMPLEMENT_DYNAMIC(ZhuJieMian_dlg, CDialogEx)

ZhuJieMian_dlg::ZhuJieMian_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ZhuJieMian_dlg::IDD, pParent)
{
	m_hicon = AfxGetApp()->LoadIcon(IDI_ICON1);
	memset(m_info,0,100);//初始化
}

ZhuJieMian_dlg::~ZhuJieMian_dlg()
{
}

void ZhuJieMian_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ZhuJieMian_dlg, CDialogEx)
	ON_BN_CLICKED(BUTTON_KaiHu, &ZhuJieMian_dlg::OnBnClickedKaihu)
	ON_COMMAND(ID_Menu, &ZhuJieMian_dlg::OnMenu)
	ON_COMMAND(ID_32783, &ZhuJieMian_dlg::On32783)
	ON_BN_CLICKED(IDC_BUTTON5, &ZhuJieMian_dlg::OnBnClickedButton5)
	ON_COMMAND(ID_32774, &ZhuJieMian_dlg::On32774)
	ON_BN_CLICKED(IDOK, &ZhuJieMian_dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ZhuJieMian_dlg 消息处理程序

void ZhuJieMian_dlg::Set_info(const char * info)
{
	strcat(m_info,"管理员【");
	strcat(m_info,info);
	strcat(m_info,"】已经登录");
	//
}

BOOL ZhuJieMian_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString mm_info(m_info);
	this->SetDlgItemTextW(Zhu_name,mm_info);

	ModifyStyleEx(0,WS_EX_APPWINDOW);//将主界面设置为当前应用程序
	SetIcon(m_hicon, TRUE);			// 设置大图标
	SetIcon(m_hicon, FALSE);		// 设置小图标
//#5312

	return TRUE;  // return TRUE unless you set the focus to a control
}


void ZhuJieMian_dlg::OnBnClickedKaihu()
{
	// TODO: 在此添加控件通知处理程序代码
	CAddCustomer dlg;
	dlg.DoModal();
}

void ZhuJieMian_dlg::OnMenu()
{
	OnBnClickedKaihu();
	// TODO: 在此添加命令处理程序代码
}


void ZhuJieMian_dlg::On32783()
{
	GuanYu dlg;
	dlg.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void ZhuJieMian_dlg::OnBnClickedButton5()
{
	CBanLiKa dlg;
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void ZhuJieMian_dlg::On32774()
{
	CBanLiKa dlg;
	dlg.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void ZhuJieMian_dlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
