#include"order.h"

Order::Order()
{
	std::ifstream ifs(ORDER_FILE, std::ios::in);
	m_size = 0;
	if (ifs.is_open())
	{
		std::string date, interval, id, name, room, status;
		while (ifs >> date && ifs >> interval && ifs >> id && ifs >> name && ifs >> room && ifs >> status)
		{
			std::string key, value;
			std::map<std::string, std::string> m;
			int pos = date.find(":", 0);
			if (pos != -1)
			{
				key = date.substr(0, pos);
				value = date.substr(pos + 1, date.size() - pos - 1);
				m.insert(make_pair(key, value));
			}
			pos = interval.find(":", 0);
			if (pos != -1)
			{
				key = interval.substr(0, pos);
				value = interval.substr(pos + 1, interval.size() - pos - 1);
				m.insert(make_pair(key, value));
			}
			pos = id.find(":", 0);
			if (pos != -1)
			{
				key = id.substr(0, pos);
				value = id.substr(pos + 1, id.size() - pos - 1);
				m.insert(make_pair(key, value));
			}
			pos = name.find(":", 0);
			if (pos != -1)
			{
				key = name.substr(0, pos);
				value = name.substr(pos + 1, name.size() - pos - 1);
				m.insert(make_pair(key, value));
			}
			pos = room.find(":", 0);
			if (pos != -1)
			{
				key = room.substr(0, pos);
				value = room.substr(pos + 1, room.size() - pos - 1);
				m.insert(make_pair(key, value));
			}
			pos = status.find(":", 0);
			if (pos != -1)
			{
				key = status.substr(0, pos);
				value = status.substr(pos + 1, status.size() - pos - 1);
				m.insert(make_pair(key, value));
			}
			m_orderDate.insert(make_pair(m_size++, m));
		}
	}
}

void Order::updateDate()
{
	std::ofstream ofs(ORDER_FILE, std::ios::trunc | std::ios::out);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date:" << m_orderDate[i]["date"] << " "
			<< "interval:" << m_orderDate[i]["interval"] << " "
			<< "stuId:" << m_orderDate[i]["stuId"] << " "
			<< "stuName:" << m_orderDate[i]["stuName"] << " "
			<< "roomId:" << m_orderDate[i]["roomId"] << " "
			<< "status:" << m_orderDate[i]["status"] << " " << std::endl;
	}
	ofs.close();
}