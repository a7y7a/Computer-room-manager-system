#pragma once
#include"identity.h"
#include"order.h"
#include<vector>

class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int tid, std::string name, std::string pwd);
	virtual void menu();
	void allOrder();
	void validOrder();

	int m_tid;
};