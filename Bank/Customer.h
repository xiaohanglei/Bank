#pragma once
class CCustomer
{
public:
	CCustomer(void);
	~CCustomer(void);
public:
	void Set_id(char s_id[21]);//
	void Set_name(char s_name[15]);//
	void Set_sex(int s_sex);//
	void Set_num(char s_num[19]);//
	void Set_tel(char s_tel[12]);//
	void Set_address(char s_address[128]);
	void Set_dat(tm * s_data);
	
	tm Get_data();
	char * Get_address();
	char * Get_id();
	char * Get_name();
	int Get_sex();
	char * Get_num();
	char * Get_tel();
private:
	char m_id[21];//账号
	char m_name[15];//姓名
	int m_sex;//性别0：女， 1：男
	char m_num[19];//身份证
	char m_tel[12];//电话
	char m_address[128];//地址
	tm m_creatdata ; //创建日期
};

