#pragma once


// CAddCustomer �Ի���

class CAddCustomer : public CDialogEx
{
	DECLARE_DYNAMIC(CAddCustomer)

public:
	CAddCustomer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddCustomer();

// �Ի�������
	enum { IDD = KaiHu };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
