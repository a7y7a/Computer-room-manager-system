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
	std::cout << "欢迎学生：" << this->m_name << "登录！" << std::endl;
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 1.申请预约 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 2.我的预约 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 3.全部预约 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 4.取消预约 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 0.注销登录 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "请选择您的操作： " << std::endl;
}

void Student::applyOrder()
{
	int date = 0, interval = 0, room = 0;
	std::cout << "请输入时间周1至周5" << std::endl;
	std::cin >> date;
	std::cout << "请输入时间段1.上午  2.下午" << std::endl;
	std::cin >> interval;
	std::cout << "请输入时间段房间号" << std::endl;
	std::cin >> room;
	std::cout << "申请成功" << std::endl;
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
		std::cout << "无记录" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == m_id)
		{
			std::cout << "预约时间: 周" << of.m_orderDate[i]["date"]
				<< " 时段: " << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午")
				<< " 房间号： " << of.m_orderDate[i]["roomId"] << " 状态: ";
			if (of.m_orderDate[i]["status"] == "1")
			{
				std::cout << "审核中" << std::endl;
			}
			if (of.m_orderDate[i]["status"] == "2")
			{
				std::cout << "审核通过" << std::endl;
			}
			if (of.m_orderDate[i]["status"] == "-1")
			{
				std::cout << "审核失败" << std::endl;
			}
			if (of.m_orderDate[i]["status"] == "0")
			{
				std::cout << "取消" << std::endl;
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
		std::cout << "无记录" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		std::cout << "预约时间: 周" << of.m_orderDate[i]["date"]
			<< " 时段: " << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午")
			<< "学号: " << of.m_orderDate[i]["stuId"]
			<< "用户名: " << of.m_orderDate[i]["stuId"]
			<< " 房间号： " << of.m_orderDate[i]["roomId"] << " 状态: ";
		if (of.m_orderDate[i]["status"] == "1")
		{
			std::cout << "审核中" << std::endl;
		}
		if (of.m_orderDate[i]["status"] == "2")
		{
			std::cout << "审核通过" << std::endl;
		}
		if (of.m_orderDate[i]["status"] == "-1")
		{
			std::cout << "审核失败" << std::endl;
		}
		if (of.m_orderDate[i]["status"] == "0")
		{
			std::cout << "取消" << std::endl;
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
		std::cout << "无记录" << std::endl;
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
					<< "预约时间: 周" << of.m_orderDate[i]["date"]
					<< " 时段: " << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午")
					<< " 房间号： " << of.m_orderDate[i]["roomId"] << " 状态: ";
				if (of.m_orderDate[i]["status"] == "1")
				{
					std::cout << "审核中" << std::endl;
				}
				if (of.m_orderDate[i]["status"] == "2")
				{
					std::cout << "审核通过" << std::endl;
				}
			}
		}
	}
	std::cout << "请输入要取消的预约， 0代表返回" << std::endl;
	int select = 0;
	std::cin >> select;
	do
	{
		if (select > 0 && select <= v.size())
		{
			of.m_orderDate[v[select - 1]]["status"] = "0";
			std::cout << "已取消" << std::endl;
			of.updateDate();
			system("pause");
			system("cls");
			return;
		}
		else if (select)
		{
			std::cout << "输入有误" << std::endl;
		}
	} while (select);
	system("pause");
	system("cls");
}