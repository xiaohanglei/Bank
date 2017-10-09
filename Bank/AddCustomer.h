#pragma once


// CAddCustomer 对话框

class CAddCustomer : public CDialogEx
{
	DECLARE_DYNAMIC(CAddCustomer)

public:
	CAddCustomer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddCustomer();

// 对话框数据
	enum { IDD = KaiHu };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
