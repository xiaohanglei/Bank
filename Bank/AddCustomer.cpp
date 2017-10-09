// AddCustomer.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "AddCustomer.h"
#include "afxdialogex.h"
#include "Customer.h"
#include "Tookit.h"
#include <iostream>
#include "CustomerDao.h"
using namespace std;


// CAddCustomer 对话框

IMPLEMENT_DYNAMIC(CAddCustomer, CDialogEx)

CAddCustomer::CAddCustomer(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddCustomer::IDD, pParent)
{

}

CAddCustomer::~CAddCustomer()
{
}

void CAddCustomer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddCustomer, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddCustomer::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAddCustomer::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAddCustomer 消息处理程序


BOOL CAddCustomer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//给单选框设置默认值
	((CButton*)this->GetDlgItem(RADIO_Nan))->SetCheck(1);
	//设置文本框的最大输入值
	

	return TRUE;  // return TRUE unless you set the focus to a control

}


void CAddCustomer::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取用户输入在控件中的值
	CCustomer customer;//定义一个用户
	//姓名
	CString cstr_name;	
	this->GetDlgItemTextW(edit_Name,cstr_name);//获得控件值
	char * p_name = CTookit::Zhongwen(cstr_name);	
	
	//性别：
	int i_sex;
	i_sex = ((CButton*)this->GetDlgItem(RADIO_Nan))->GetCheck();
	
	//账号
	char i_id[21] = "A";
	CTookit::rand_id(i_id);

	//身份证号
	CString cstr_shenfen;
	this->GetDlgItemTextW(edit_Shenfen,cstr_shenfen);
	char * p_shenfen = CTookit::Zhongwen(cstr_shenfen);//转换

	//日期
	//生成当前日期
	time_t tt = time(NULL);
	tm * p_time = localtime(&tt);
	//手机号
	CString cstr_tel;
	this->GetDlgItemTextW(edit_Tel,cstr_tel);
	char * p_tel = CTookit::Zhongwen(cstr_tel);

	//地址
	CString cstr_address;
	this->GetDlgItemTextW(edit_address,cstr_address);
	char * p_address = CTookit::Zhongwen(cstr_address);

	//将信息保存到客户类对象中
	customer.Set_name(p_name);//姓名
	customer.Set_sex(i_sex);//性别
	customer.Set_id(i_id);//帐号
	customer.Set_num(p_shenfen);//身份证
	customer.Set_dat(p_time);//日期时间
	customer.Set_tel(p_tel);//设置手机号
	customer.Set_address(p_address);//设置地址

	CCustomerDao cus ;
	if (cus.Save(&customer))//调用文件操作类函数，写入文件
	{
		CString Tishi (i_id);//提示信息
		Tishi = _T("\n\n\t开户成功!\n请牢记您的账号：") + Tishi;
		MessageBox(Tishi,_T("成功！"));
		CDialogEx::OnOK();
	}
	
	return ;
	
}


void CAddCustomer::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
