// ZhuJieMian_dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "ZhuJieMian_dlg.h"
#include "afxdialogex.h"
#include "AddCustomer.h"
#include "GuanYu.h"
#include "BanLiKa.h"

// ZhuJieMian_dlg �Ի���

IMPLEMENT_DYNAMIC(ZhuJieMian_dlg, CDialogEx)

ZhuJieMian_dlg::ZhuJieMian_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ZhuJieMian_dlg::IDD, pParent)
{
	m_hicon = AfxGetApp()->LoadIcon(IDI_ICON1);
	memset(m_info,0,100);//��ʼ��
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


// ZhuJieMian_dlg ��Ϣ�������

void ZhuJieMian_dlg::Set_info(const char * info)
{
	strcat(m_info,"����Ա��");
	strcat(m_info,info);
	strcat(m_info,"���Ѿ���¼");
	//
}

BOOL ZhuJieMian_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString mm_info(m_info);
	this->SetDlgItemTextW(Zhu_name,mm_info);

	ModifyStyleEx(0,WS_EX_APPWINDOW);//������������Ϊ��ǰӦ�ó���
	SetIcon(m_hicon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hicon, FALSE);		// ����Сͼ��
//#5312

	return TRUE;  // return TRUE unless you set the focus to a control
}


void ZhuJieMian_dlg::OnBnClickedKaihu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAddCustomer dlg;
	dlg.DoModal();
}

void ZhuJieMian_dlg::OnMenu()
{
	OnBnClickedKaihu();
	// TODO: �ڴ���������������
}


void ZhuJieMian_dlg::On32783()
{
	GuanYu dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}


void ZhuJieMian_dlg::OnBnClickedButton5()
{
	CBanLiKa dlg;
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ZhuJieMian_dlg::On32774()
{
	CBanLiKa dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}


void ZhuJieMian_dlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
