#include"manager.h"

void Manager::initVector()
{
	vs.clear();
	vt.clear();

	std::ifstream ifs(STUDENT_FILE, std::ios::in);
	if (ifs.is_open())
	{
		Student s;
		while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
		{
			vs.push_back(s);
		}
	}
	ifs.close();
	ifs.open(TEACHER_FILE, std::ios::in);
	if (ifs.is_open())
	{
		Teacher t;
		while (ifs >> t.m_tid && ifs >> t.m_name && ifs >> t.m_pwd)
		{
			vt.push_back(t);
		}
	}
	ifs.close();
}

bool Manager::cheakRepead(int id, int type)
{
	if (type == 1)
	{
		for (std::vector<Student>::iterator sit = vs.begin(); sit != vs.end(); sit++)
		{
			if (sit->m_id == id)
			{
				return true;
			}
		}
	}
	if (type == 2)
	{
		for (std::vector<Teacher>::iterator tit = vt.begin(); tit != vt.end(); tit++)
		{
			if (tit->m_tid == id)
			{
				return true;
			}
		}
	}
	return false;
}

Manager::Manager()
{

}

Manager::Manager(std::string name, std::string pwd)
{
	m_name = name;
	m_pwd = pwd;

	initVector();

	vc.clear();

	std::ifstream ifs(COMPUTER_FILE, std::ios::in);
	if (ifs.is_open())
	{
		Computer c;
		while (ifs >> c.m_cid && ifs >> c.m_num)
		{
			vc.push_back(c);
		}
	}
	ifs.close();
}

void Manager::menu()
{
	std::cout << "欢迎管理员：" << this->m_name << "登录！" << std::endl;
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 1.添加账号 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 2.查看账号 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 3.查看机房 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 4.清空预约 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 0.注销登录 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "请选择您的操作： " << std::endl;
}

void Manager::addPerson()
{
	std::cout << "添加： 1.学生 2.老师 0.取消" << std::endl;
	int select = 0;
	std::cin >> select;

	if (select == 0)
	{
		system("pasue");
		system("cls");
		return;
	}

	std::string fileName;
	int id;
	std::string name;
	std::string pwd;

	if (select == 1)
	{
		std::cout << "请输入学号" << std::endl;
		fileName = STUDENT_FILE;
	}
	if (select == 2)
	{
		std::cout << "请输入职工号" << std::endl;
		fileName = TEACHER_FILE;
	}

	bool ret = true;
	do
	{
		std::cin >> id;
		ret = cheakRepead(id, select);
		if (ret)
		{
			std::cout << "重复" << std::endl;
		}
	} while (ret);
	std::cout << "请输入用户名" << std::endl;
	std::cin >> name;
	std::cout << "请输入密码" << std::endl;
	std::cin >> pwd;

	std::ofstream ofs(fileName, std::ios::out | std::ios::app);
	ofs << id << " " << name << " " << pwd << " " << std::endl;

	std::cout << "添加成功" << std::endl;

	ofs.close();
	initVector();

	system("pause");
	system("cls");
}

void Manager::showPerson()
{
	std::cout << "显示： 1.学生 2.老师 0.取消" << std::endl;
	int select = 0;
	std::cin >> select;

	if (select == 0)
	{
		system("pasue");
		system("cls");
		return;
	}
	if (select == 1)
	{
		std::for_each(vs.begin(), vs.end(), [](Student s) {std::cout << "学号： " << s.m_id << " 用户名: " << s.m_name << " 密码： " << s.m_pwd << std::endl; });
	}
	if (select == 2)
	{
		std::for_each(vt.begin(), vt.end(), [](Teacher t) {std::cout << "职工号： " << t.m_tid << " 用户名: " << t.m_name << " 密码： " << t.m_pwd << std::endl; });
	}

	system("pause");
	system("cls");
}

void Manager::showCompter()
{
	std::for_each(vc.begin(), vc.end(), [](Computer c) {std::cout << "机房号： " << c.m_cid << " 机位: " << c.m_num << std::endl; });
	system("pause");
	system("cls");
}

void Manager::cleanOrder()
{
	std::ofstream ofs(ORDER_FILE, std::ios::trunc);
	ofs.close();

	std::cout << "清空成功" << std::endl;

	system("pause");
	system("cls");
}