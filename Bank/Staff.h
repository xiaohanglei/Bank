#pragma once
class CStaff
{
public:
	CStaff(void);
	CStaff(char id[21] , char password[7] , char name[15] , char bankname[41] , int nper);
	~CStaff(void);
public:
	void Set_id(char s_id[21]); //�����ʺ�
	char * Get_id();//����ʺ�

	void Set_password(char s_password[7]);
	char * Get_password();

	void Set_name(char s_name[15]);
	char * Get_name();

	void Set_bankname(char s_bankname[41]);
	char * Get_bankname();

	void Set_nper(int s_nper);
	int Get_nper();	

private:
	char m_id[21];//id
	char m_password[7];//����
	char m_name[15];//����
	char m_bankname[41];//��������
	int m_nper;//Ȩ��
};

