#include "stdafx.h"
#include "StaffDao.h"
#include <fstream>
using namespace std;
#define MAX_BUF 100

CStaffDao::CStaffDao(void)
{
	p_staff = NULL;
}


CStaffDao::~CStaffDao(void)
{
	delete p_staff;
}
BOOL CStaffDao::login(const char * l_id , const char * l_password)//验证银行管理用户名和密码！
{
	//打开文件
	ifstream fileinfo;
	fileinfo.open("Staff.txt",ios::in);
	if (!fileinfo)
	{
		return FALSE;
	}
	//读取文件
	BOOL flag = FALSE;

	char staffinfo [MAX_BUF] = {'0'};
	p_staff = NULL;
	while(fileinfo.getline(staffinfo,sizeof(staffinfo)))//读取一整行)
	{
		//解析
		p_staff = prasestaff(staffinfo);//将接收到的一行字符，
		//通过解析，获得一个银行管理员对象

		//将参数与解析出来的用户名和密码进行匹配，
		if (strcmp( p_staff->Get_id() , l_id) == 0 
			&& 
			strcmp(p_staff->Get_password(),l_password) == 0)
		{
			flag = TRUE;
			//
			break;
		}
	}

	//关闭文件
	fileinfo.close();
	return flag;
}

CStaff * CStaffDao:: prasestaff(char * pstaffinfo)//解析
{
	char a_staffinfo[5][MAX_BUF] = {'0'};
	int index = 0 ;//数组下标
	char * fengefu = "##";//分隔符
	char * pbuf = NULL;
	char * pstr = NULL;

	CStaff * pStaff = NULL;//用于返回银行管理员信息对象指针
	pStaff = new CStaff();//从堆上分配一个对象

	pbuf = pstaffinfo;

	while((pstr = strtok(pbuf,fengefu)) != NULL)
	{
		strcpy(a_staffinfo[index],pstr );
		index++;
		pbuf = NULL ;
	}

	pStaff->Set_id (a_staffinfo[0]);
	pStaff->Set_password (a_staffinfo[1]);
	pStaff->Set_name (a_staffinfo[2]);
	pStaff->Set_bankname (a_staffinfo[3]);
	int n_p = atoi(a_staffinfo[4]);
	pStaff->Set_nper (n_p);

	return pStaff;

}
char * CStaffDao::ret_name()//返回该已经匹配到的对象的名称用于传递到界面上
{
	return p_staff->Get_name();
}