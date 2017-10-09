#pragma once


// CBanLiKa 对话框

class CBanLiKa : public CDialogEx
{
	DECLARE_DYNAMIC(CBanLiKa)

public:
	CBanLiKa(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBanLiKa();

// 对话框数据
	enum { IDD = BanLiKa };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
