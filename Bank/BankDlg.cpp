
// BankDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "BankDlg.h"
#include "afxdialogex.h"
#include "ZhuJieMian_dlg.h"
#include "StaffDao.h"
#include "Tookit.h"
#include <mmsystem.h>

#include "BanLiKa.h"
#pragma comment(lib,"winmm.lib")//������
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32774();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(ID_32774, &CAboutDlg::On32774)
END_MESSAGE_MAP()


// CBankDlg �Ի���



CBankDlg::CBankDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBankDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CBankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBankDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1_Ok, &CBankDlg::OnBnClickedButton1Ok)
	ON_BN_CLICKED(ID_APP_EXIT, &CBankDlg::OnBnClickedAppExit)
END_MESSAGE_MAP()


// CBankDlg ��Ϣ�������

BOOL CBankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

		//*********************************************����Ҫ��������***************************

	PlaySound(_T("yisheng.wav"),NULL,SND_ASYNC | SND_NODEFAULT);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CBankDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBankDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBankDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBankDlg::OnBnClickedButton1Ok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strname ;
	CString password ;
	this->GetDlgItemTextW(IDC_EDIT1_Uerse,strname); //��ȡ�û���
	this->GetDlgItemTextW(IDC_EDIT2_password,password);//��ȡ����

	//���ù����ࣺ��CString  ת����  char *

	char * p_strname = CTookit::Zhongwen(strname);

	char * p_password= CTookit::Zhongwen(password);


	//�����ຯ���������û����������ƥ��
	CStaffDao sta;
	if (sta.login(p_strname,p_password))
	{		
		ZhuJieMian_dlg dlg;
		char * name = sta.ret_name();//���ظö��������
		
		dlg.Set_info(name);
		this->ShowWindow(SW_HIDE);//���ص�¼����)
			
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: �ڴ˷��ô����ʱ��
			//  ��ȷ�������رնԻ���Ĵ���
			this->ShowWindow(SW_SHOW);
			//�˻ص���¼�����Ժ�����ı����ֵ
			this->GetDlgItem(IDC_EDIT1_Uerse)->SetWindowTextW(_T(""));
			this->GetDlgItem(IDC_EDIT2_password)->SetWindowTextW(_T(""));
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: �ڴ˷��ô����ʱ��
			//  ��ȡ�������رնԻ���Ĵ���
			this->ShowWindow(SW_SHOW);
		}
	}
	else
	{
		MessageBox(_T("�û��������������"),_T("ʧ��"));
	}
}


void CBankDlg::OnBnClickedAppExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CAboutDlg::On32774()
{
	CBanLiKa dlg;
	dlg.DoModal();
	// TODO: �ڴ���������������
}
