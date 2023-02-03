#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"globalFile.h"

class Order
{
public:
	Order();
	void updateDate();

	int m_size;
	std::map<int, std::map<std::string, std::string>> m_orderDate;
};
