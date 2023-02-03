#include"teacher.h"

Teacher::Teacher()
{

}
Teacher::Teacher(int tid, std::string name, std::string pwd)
{
	m_tid = tid;
	m_name = name;
	m_pwd = pwd;
}
void Teacher::menu()
{
	std::cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << std::endl;
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 1.����ԤԼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 2.���ԤԼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 0.ע����¼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "��ѡ�����Ĳ����� " << std::endl;
}
void Teacher::allOrder()
{
	Order of;
	if (!of.m_size)
	{
		std::cout << "�޼�¼" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		std::cout << "ԤԼʱ��: ��" << of.m_orderDate[i]["date"]
			<< " ʱ��: " << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����")
			<< "ѧ��: " << of.m_orderDate[i]["stuId"]
			<< "�û���: " << of.m_orderDate[i]["stuId"]
			<< " ����ţ� " << of.m_orderDate[i]["roomId"] << " ״̬: ";
		if (of.m_orderDate[i]["status"] == "1")
		{
			std::cout << "�����" << std::endl;
		}
		if (of.m_orderDate[i]["status"] == "2")
		{
			std::cout << "���ͨ��" << std::endl;
		}
		if (of.m_orderDate[i]["status"] == "-1")
		{
			std::cout << "���ʧ��" << std::endl;
		}
		if (of.m_orderDate[i]["status"] == "0")
		{
			std::cout << "ȡ��" << std::endl;
		}
	}
	system("pause");
	system("cls");
}
void Teacher::validOrder()
{
	Order of;
	if (!of.m_size)
	{
		std::cout << "�޼�¼" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	std::vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			std::cout << ++index << ". "
				<< "ԤԼʱ��: ��" << of.m_orderDate[i]["date"]
				<< " ʱ��: " << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����")
				<< " ����ţ� " << of.m_orderDate[i]["roomId"];
		}
	}
	std::cout << "������Ҫ��˵�ԤԼ�� 0������" << std::endl;
	int select = 0;
	std::cin >> select;
	do
	{
		if (select > 0 && select <= v.size())
		{
			std::cout << "��������˽��" << std::endl;
			std::cout << "2.ͨ��  -1.�ܾ�  0.ȡ��" << std::endl;
			int ret = 0;
			std::cin >> ret;
			if (ret == 2)
			{
				of.m_orderDate[v[select - 1]]["status"] = "2";
			}
			if (ret == -1)
			{
				of.m_orderDate[v[select - 1]]["status"] = "-1";
			}
			std::cout << "������" << std::endl;
			of.updateDate();
			system("pause");
			system("cls");
			return;
		}
		else if (select)
		{
			std::cout << "��������" << std::endl;
		}
	} while (select);
	system("pause");
	system("cls");
}
