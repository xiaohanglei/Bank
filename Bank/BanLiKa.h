#pragma once


// CBanLiKa �Ի���

class CBanLiKa : public CDialogEx
{
	DECLARE_DYNAMIC(CBanLiKa)

public:
	CBanLiKa(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBanLiKa();

// �Ի�������
	enum { IDD = BanLiKa };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
