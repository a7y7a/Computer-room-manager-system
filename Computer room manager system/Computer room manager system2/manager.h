#pragma once
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computer.h"

class Manager :public Identity
{
public:
	Manager();
	Manager(std::string name, std::string pwd);
	virtual void menu();
	void addPerson();
	void showPerson();
	void showCompter();
	void cleanOrder();
	void initVector();
	bool cheakRepead(int id, int type);

	std::vector<Student> vs;
	std::vector<Teacher> vt;
	std::vector<Computer> vc;
};