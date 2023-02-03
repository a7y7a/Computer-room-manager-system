#include"student.h"

Student::Student()
{

}

Student::Student(int id, std::string name, std::string pwd)
{
	m_id = id;
	m_name = name;
	m_pwd = pwd;
}

void Student::menu()
{
	std::cout << "��ӭѧ����" << this->m_name << "��¼��" << std::endl;
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 1.����ԤԼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 2.�ҵ�ԤԼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 3.ȫ��ԤԼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 4.ȡ��ԤԼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 0.ע����¼ |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "��ѡ�����Ĳ����� " << std::endl;
}

void Student::applyOrder()
{
	int date = 0, interval = 0, room = 0;
	std::cout << "������ʱ����1����5" << std::endl;
	std::cin >> date;
	std::cout << "������ʱ���1.����  2.����" << std::endl;
	std::cin >> interval;
	std::cout << "������ʱ��η����" << std::endl;
	std::cin >> room;
	std::cout << "����ɹ�" << std::endl;
	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << m_id << " ";
	ofs << "stuName:" << m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << std::endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::myOrder()
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
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == m_id)
		{
			std::cout << "ԤԼʱ��: ��" << of.m_orderDate[i]["date"]
				<< " ʱ��: " << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����")
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
	}
	system("pause");
	system("cls");
}

void Student::allOrder()
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

void Student::cancelOrder()
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
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == m_id)
		{
			if (of.m_orderDate[i]["status"] == "1" || of.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				std::cout << ++index << ". "
					<< "ԤԼʱ��: ��" << of.m_orderDate[i]["date"]
					<< " ʱ��: " << (of.m_orderDate[i]["interval"] == "1" ? "����" : "����")
					<< " ����ţ� " << of.m_orderDate[i]["roomId"] << " ״̬: ";
				if (of.m_orderDate[i]["status"] == "1")
				{
					std::cout << "�����" << std::endl;
				}
				if (of.m_orderDate[i]["status"] == "2")
				{
					std::cout << "���ͨ��" << std::endl;
				}
			}
		}
	}
	std::cout << "������Ҫȡ����ԤԼ�� 0������" << std::endl;
	int select = 0;
	std::cin >> select;
	do
	{
		if (select > 0 && select <= v.size())
		{
			of.m_orderDate[v[select - 1]]["status"] = "0";
			std::cout << "��ȡ��" << std::endl;
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