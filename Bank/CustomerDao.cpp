#include "stdafx.h"
#include "CustomerDao.h"
#include <fstream>
#define COSTOMER_BUF 200
using namespace std;


CCustomerDao::CCustomerDao(void)
{
}


CCustomerDao::~CCustomerDao(void)
{
}
BOOL CCustomerDao:: Save(CCustomer * Cus)//文件的写入
{
	char t_buf[COSTOMER_BUF] = {'0'};//用于存储该对象的所有信息（一行）

	BOOL flag = FALSE;
	char * c_id = Cus->Get_id();//获取对象帐号
	char * c_name = Cus->Get_name();//获取对象姓名
	int c_sex = Cus->Get_sex();//获取对象性别
	char * c_shenfen = Cus->Get_num();//获取对象身份证
	char * c_tel = Cus->Get_tel();//获取对象电话
	char * c_address = Cus->Get_address();//获取对象地址
		
	//获取对象的日期

	char a_time[15] = {'0'};//
	strftime(a_time,sizeof(a_time),"%Y年%m月%d日",&(Cus->Get_data()));


	sprintf(t_buf,"%s##%s##%d##%s##%s##%s##%s",c_id,c_name,c_sex,c_shenfen,c_tel,c_address,a_time);
	char * p = t_buf;

	//打开文件
	ofstream outfile ;
	outfile.open("Customer.txt",ios::app);//以追加方式打开
	//写入文件
	if (outfile.write(t_buf,sizeof(t_buf)))
	{
		outfile.write("\r\n",2);
		flag = TRUE;
	}

	//清空缓存
	outfile.flush();
	//关闭文件
	outfile.close();
	return flag;
}