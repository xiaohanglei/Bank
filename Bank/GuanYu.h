#pragma once


// GuanYu �Ի���

class GuanYu : public CDialogEx
{
	DECLARE_DYNAMIC(GuanYu)

public:
	GuanYu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~GuanYu();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	//fadsjkfadsfadfdadf
	//���ַ��ַ�ʦ������
};
