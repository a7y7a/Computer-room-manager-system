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
	std::cout << "欢迎教师：" << this->m_name << "登录！" << std::endl;
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 1.所有预约 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 2.审核预约 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t| 0.注销登录 |\n";
	std::cout << "\t\t| |\n";
	std::cout << "\t\t ---------------------------------\n";
	std::cout << "请选择您的操作： " << std::endl;
}
void Teacher::allOrder()
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
void Teacher::validOrder()
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
		if (of.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			std::cout << ++index << ". "
				<< "预约时间: 周" << of.m_orderDate[i]["date"]
				<< " 时段: " << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午")
				<< " 房间号： " << of.m_orderDate[i]["roomId"];
		}
	}
	std::cout << "请输入要审核的预约， 0代表返回" << std::endl;
	int select = 0;
	std::cin >> select;
	do
	{
		if (select > 0 && select <= v.size())
		{
			std::cout << "请输入审核结果" << std::endl;
			std::cout << "2.通过  -1.拒绝  0.取消" << std::endl;
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
			std::cout << "审核完毕" << std::endl;
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
