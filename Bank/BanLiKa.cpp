// BanLiKa.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "BanLiKa.h"
#include "afxdialogex.h"
#include "Card.h"
#include "Tookit.h"
#include "Carddao.h"


// CBanLiKa 对话框

IMPLEMENT_DYNAMIC(CBanLiKa, CDialogEx)

CBanLiKa::CBanLiKa(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBanLiKa::IDD, pParent)
{

}

CBanLiKa::~CBanLiKa()
{
}

void CBanLiKa::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBanLiKa, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBanLiKa::OnBnClickedOk)
END_MESSAGE_MAP()


// CBanLiKa 消息处理程序


void CBanLiKa::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CCard card;

	CString cstr_id;
	this->GetDlgItemTextW(edit_id,cstr_id);//获取控件的值
	char * p_id = CTookit::Zhongwen(cstr_id);

	CString cstr_password ;
	this->GetDlgItemTextW(edit_password,cstr_password);
	char * p_password  = CTookit::Zhongwen(cstr_password);

	CString cstr_password_2 ;
	this->GetDlgItemTextW(edit_password_2,cstr_password_2);
	char * p_password_2 = CTookit::Zhongwen(cstr_password_2);

	CString cstr_money;
	this->GetDlgItemTextW(edit_money,cstr_money);
	//将**************         cstring      转换成  int         *****
	int i_money = _ttoi(cstr_money);

	if (cstr_password == cstr_password_2)
	{
		char p_kahao[22] = "K";
		CTookit::rand_id(p_kahao);//生成随机数

			//日期
		//生成当前日期
		time_t tt = time(NULL);
		tm * p_time = localtime(&tt);

		//将信息设置到 卡  类对象
		card.Set_id(p_id);
		card.Set_kahao(p_kahao);
		card.Set_password(p_password);
		card.Set_money(i_money);
		card.Set_bank("中国银行");
		card.Set_createdate( p_time);

		CCarddao ccar;

		if (ccar.Save(&card))
		{
			CString name(ccar.Get_name());
			CString KaHao (card.Get_kahao());
			CString TiShi = _T("恭喜您【") + name +  _T("】办理储蓄卡成功\n");
			TiShi = TiShi + _T("请牢记您的卡号：") + KaHao;

			MessageBox(TiShi,_T("成功！"));
			CDialogEx::OnOK();//关闭对话框
		}
		else
		{
			MessageBox(_T("绑定失败，储蓄卡需要绑定在账户上！，请先开户!"),_T("失败"));
		}
	}
	else
	{
		MessageBox(_T("两次密码不一致"),_T("失败"));
	}

	//
}
