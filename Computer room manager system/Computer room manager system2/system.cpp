#include<iostream>
#include"globalFile.h"
#include<string>
#include"identity.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include"manager.h"

void ManagerMenu(Identity* person)
{
	int select = 0;
	do
	{
		person->menu();
		Manager* man = (Manager*)person;
		std::cin >> select;
		switch (select)
		{
		case 0:
			delete person;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			break;
		case 1:
			man->addPerson();
			break;
		case 2:
			man->showPerson();
			break;
		case 3:
			man->showCompter();
			break;
		case 4:
			man->cleanOrder();
			break;
		}
	} while (select);
}

void StudentMenu(Identity* person)
{
	int select = 0;
	do
	{
		person->menu();
		Student* stu = (Student*)person;
		std::cin >> select;
		switch (select)
		{
		case 0:
			delete person;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			break;
		case 1:
			stu->applyOrder();
			break;
		case 2:
			stu->myOrder();
			break;
		case 3:
			stu->allOrder();
			break;
		case 4:
			stu->cancelOrder();
			break;
		}
	} while (select);
}

void TeacherMenu(Identity* person)
{
	int select = 0;
	do
	{
		person->menu();
		Teacher* tea = (Teacher*)person;
		std::cin >> select;
		switch (select)
		{
		case 0:
			delete person;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			break;
		case 1:
			tea->allOrder();
			break;
		case 2:
			tea->validOrder();
			break;
		}
	} while (select);
}

void Login(std::string fileName, int type)
{
	Identity* person = NULL;

	std::ifstream ifs(fileName, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "�ļ�������" << std::endl;
		ifs.close();
		return;
	}

	int id = 0;
	std::string name;
	std::string pwd;

	if (type == 1)
	{
		std::cout << "������ѧ��" << std::endl;
		std::cin >> id;
	}
	if (type == 2)
	{
		std::cout << "������ְ����" << std::endl;
		std::cin >> id;
	}

	std::cout << "�������û���" << std::endl;
	std::cin >> name;
	std::cout << "����������" << std::endl;
	std::cin >> pwd;

	if (type == 1)
	{
		int fid = 0;
		std::string fname;
		std::string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}
		}
	}
	if (type == 2)
	{
		int fid = 0;
		std::string fname;
		std::string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	if (type == 3)
	{
		std::string fname;
		std::string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMenu(person);
				return;
			}
		}
	}

	std::cout << "��½ʧ��" << std::endl;

	system("pause");
	system("cls");

	return;
}

int main() 
{
	int select = 0;
	do
	{
		std::cout << "====================== ��ӭ�������ǲ��ͻ���ԤԼϵͳ =====================" << std::endl;
		std::cout << std::endl << "�������������" << std::endl;
		std::cout << "\t\t -------------------------------\n";
		std::cout << "\t\t| |\n";
		std::cout << "\t\t| 1.ѧ������ |\n";
		std::cout << "\t\t| |\n";
		std::cout << "\t\t| 2.�� ʦ |\n";
		std::cout << "\t\t| |\n";
		std::cout << "\t\t| 3.�� �� Ա |\n";
		std::cout << "\t\t| |\n";
		std::cout << "\t\t| 0.�� �� |\n";
		std::cout << "\t\t| |\n";
		std::cout << "\t\t -------------------------------\n";
		std::cout << "��������ѡ��: ";

		std::cin >> select;

		switch (select)
		{
		case 0:
			std::cout << "exit" << std::endl;
			break;
		case 1:
			Login(STUDENT_FILE, 1);
			break;
		case 2:
			Login(TEACHER_FILE, 2);
			break;
		case 3:
			Login(ADMIN_FILE, 3);
			break;
		default:
			std::cout << "remake" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	} while (select);

	system("pause");

	return 0;
}