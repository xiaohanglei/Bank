// BanLiKa.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "BanLiKa.h"
#include "afxdialogex.h"
#include "Card.h"
#include "Tookit.h"
#include "Carddao.h"


// CBanLiKa �Ի���

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


// CBanLiKa ��Ϣ�������


void CBanLiKa::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCard card;

	CString cstr_id;
	this->GetDlgItemTextW(edit_id,cstr_id);//��ȡ�ؼ���ֵ
	char * p_id = CTookit::Zhongwen(cstr_id);

	CString cstr_password ;
	this->GetDlgItemTextW(edit_password,cstr_password);
	char * p_password  = CTookit::Zhongwen(cstr_password);

	CString cstr_password_2 ;
	this->GetDlgItemTextW(edit_password_2,cstr_password_2);
	char * p_password_2 = CTookit::Zhongwen(cstr_password_2);

	CString cstr_money;
	this->GetDlgItemTextW(edit_money,cstr_money);
	//��**************         cstring      ת����  int         *****
	int i_money = _ttoi(cstr_money);

	if (cstr_password == cstr_password_2)
	{
		char p_kahao[22] = "K";
		CTookit::rand_id(p_kahao);//���������

			//����
		//���ɵ�ǰ����
		time_t tt = time(NULL);
		tm * p_time = localtime(&tt);

		//����Ϣ���õ� ��  �����
		card.Set_id(p_id);
		card.Set_kahao(p_kahao);
		card.Set_password(p_password);
		card.Set_money(i_money);
		card.Set_bank("�й�����");
		card.Set_createdate( p_time);

		CCarddao ccar;

		if (ccar.Save(&card))
		{
			CString name(ccar.Get_name());
			CString KaHao (card.Get_kahao());
			CString TiShi = _T("��ϲ����") + name +  _T("��������ɹ�\n");
			TiShi = TiShi + _T("���μ����Ŀ��ţ�") + KaHao;

			MessageBox(TiShi,_T("�ɹ���"));
			CDialogEx::OnOK();//�رնԻ���
		}
		else
		{
			MessageBox(_T("��ʧ�ܣ������Ҫ�����˻��ϣ������ȿ���!"),_T("ʧ��"));
		}
	}
	else
	{
		MessageBox(_T("�������벻һ��"),_T("ʧ��"));
	}

	//
}
