// AddCustomer.cpp : ʵ���ļ�
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


// CAddCustomer �Ի���

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


// CAddCustomer ��Ϣ�������


BOOL CAddCustomer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//����ѡ������Ĭ��ֵ
	((CButton*)this->GetDlgItem(RADIO_Nan))->SetCheck(1);
	//�����ı�����������ֵ
	

	return TRUE;  // return TRUE unless you set the focus to a control

}


void CAddCustomer::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ȡ�û������ڿؼ��е�ֵ
	CCustomer customer;//����һ���û�
	//����
	CString cstr_name;	
	this->GetDlgItemTextW(edit_Name,cstr_name);//��ÿؼ�ֵ
	char * p_name = CTookit::Zhongwen(cstr_name);	
	
	//�Ա�
	int i_sex;
	i_sex = ((CButton*)this->GetDlgItem(RADIO_Nan))->GetCheck();
	
	//�˺�
	char i_id[21] = "A";
	CTookit::rand_id(i_id);

	//���֤��
	CString cstr_shenfen;
	this->GetDlgItemTextW(edit_Shenfen,cstr_shenfen);
	char * p_shenfen = CTookit::Zhongwen(cstr_shenfen);//ת��

	//����
	//���ɵ�ǰ����
	time_t tt = time(NULL);
	tm * p_time = localtime(&tt);
	//�ֻ���
	CString cstr_tel;
	this->GetDlgItemTextW(edit_Tel,cstr_tel);
	char * p_tel = CTookit::Zhongwen(cstr_tel);

	//��ַ
	CString cstr_address;
	this->GetDlgItemTextW(edit_address,cstr_address);
	char * p_address = CTookit::Zhongwen(cstr_address);

	//����Ϣ���浽�ͻ��������
	customer.Set_name(p_name);//����
	customer.Set_sex(i_sex);//�Ա�
	customer.Set_id(i_id);//�ʺ�
	customer.Set_num(p_shenfen);//���֤
	customer.Set_dat(p_time);//����ʱ��
	customer.Set_tel(p_tel);//�����ֻ���
	customer.Set_address(p_address);//���õ�ַ

	CCustomerDao cus ;
	if (cus.Save(&customer))//�����ļ������ຯ����д���ļ�
	{
		CString Tishi (i_id);//��ʾ��Ϣ
		Tishi = _T("\n\n\t�����ɹ�!\n���μ������˺ţ�") + Tishi;
		MessageBox(Tishi,_T("�ɹ���"));
		CDialogEx::OnOK();
	}
	
	return ;
	
}


void CAddCustomer::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
