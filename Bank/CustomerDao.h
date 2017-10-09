#pragma once
#include "Customer.h"
class CCustomerDao
{
public:
	CCustomerDao(void);
	~CCustomerDao(void);
public:
	BOOL Save(CCustomer * Cus);//文件的写入
};

