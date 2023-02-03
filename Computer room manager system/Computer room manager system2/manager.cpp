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
	std::cout << "��ӭ����Ա��" << this->m_name << "��¼��" << std::endl;
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 1.����˺� |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 2.�鿴�˺� |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 3.�鿴���� |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 4.���ԤԼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 0.ע����¼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "��ѡ�����Ĳ����� " << std::endl;
}

void Manager::addPerson()
{
	std::cout << "��ӣ� 1.ѧ�� 2.��ʦ 0.ȡ��" << std::endl;
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
		std::cout << "������ѧ��" << std::endl;
		fileName = STUDENT_FILE;
	}
	if (select == 2)
	{
		std::cout << "������ְ����" << std::endl;
		fileName = TEACHER_FILE;
	}

	bool ret = true;
	do
	{
		std::cin >> id;
		ret = cheakRepead(id, select);
		if (ret)
		{
			std::cout << "�ظ�" << std::endl;
		}
	} while (ret);
	std::cout << "�������û���" << std::endl;
	std::cin >> name;
	std::cout << "����������" << std::endl;
	std::cin >> pwd;

	std::ofstream ofs(fileName, std::ios::out | std::ios::app);
	ofs << id << " " << name << " " << pwd << " " << std::endl;

	std::cout << "��ӳɹ�" << std::endl;

	ofs.close();
	initVector();

	system("pause");
	system("cls");
}

void Manager::showPerson()
{
	std::cout << "��ʾ�� 1.ѧ�� 2.��ʦ 0.ȡ��" << std::endl;
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
		std::for_each(vs.begin(), vs.end(), [](Student s) {std::cout << "ѧ�ţ� " << s.m_id << " �û���: " << s.m_name << " ���룺 " << s.m_pwd << std::endl; });
	}
	if (select == 2)
	{
		std::for_each(vt.begin(), vt.end(), [](Teacher t) {std::cout << "ְ���ţ� " << t.m_tid << " �û���: " << t.m_name << " ���룺 " << t.m_pwd << std::endl; });
	}

	system("pause");
	system("cls");
}

void Manager::showCompter()
{
	std::for_each(vc.begin(), vc.end(), [](Computer c) {std::cout << "�����ţ� " << c.m_cid << " ��λ: " << c.m_num << std::endl; });
	system("pause");
	system("cls");
}

void Manager::cleanOrder()
{
	std::ofstream ofs(ORDER_FILE, std::ios::trunc);
	ofs.close();

	std::cout << "��ճɹ�" << std::endl;

	system("pause");
	system("cls");
}