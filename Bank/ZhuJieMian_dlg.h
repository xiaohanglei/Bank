#pragma once


// ZhuJieMian_dlg �Ի���

class ZhuJieMian_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ZhuJieMian_dlg)

public:
	ZhuJieMian_dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ZhuJieMian_dlg();

// �Ի�������
	enum { IDD = ZhuJieMian };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
protected:
	HICON m_hicon;
public:
	void Set_info(const char * info);//
private:
	char m_info[100] ;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedKaihu();
	afx_msg void OnMenu();
	afx_msg void On32783();
	afx_msg void OnBnClickedButton5();
	afx_msg void On32774();
	afx_msg void OnBnClickedOk();
};
