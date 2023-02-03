#pragma once
#include"identity.h"
#include"order.h"
#include<vector>

class Student:public Identity
{
public:
	Student();
	Student(int id, std::string name, std::string pwd);
	virtual void menu();
	void applyOrder();
	void myOrder();
	void allOrder();
	void cancelOrder();

	int m_id;
};
