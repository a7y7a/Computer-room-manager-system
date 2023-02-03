#pragma once
#include<iostream>
#include<string>
#include"globalFile.h"
#include<fstream>

class Identity
{
public:
	virtual void menu() = 0;

	std::string m_name;
	std::string m_pwd;
};