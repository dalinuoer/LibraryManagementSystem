#include "UserDao.h"
#include <iostream>

using namespace std;

UserDao::UserDao(const string &filename) : dao(filename), filename(filename)
{
}

UserDao::~UserDao()
{
}

int UserDao::getPosition(int id)
{
	User data;
	file.open(filename, ios::binary | ios::in);
	file.seekg(ios::beg);
	bool found = false;
	while (!file.eof())
	{
		file.read((char*)&data, sizeof(User));
		if (data.getId() == id)
		{
			found = true;
			break;
		}
	}
	int pos = 0;
	if (found)
	{
		pos = file.tellg() - (long long)sizeof(User);
	}
	else
	{
		pos = -1;
	}
	file.close();
	return pos;
}

bool UserDao::insertUser(const User &user)
{
	file.open(filename, ios::binary | ios::out | ios::app);
	if (!file)
	{
		cout << "打开文件失败" << endl;
	}
	file.write((char*)&user, sizeof(User));
	file.close();
	return true;
}

bool UserDao::updateUser(int id, const User &user)
{
	int pos = getPosition(id);
	if (pos != -1)
	{
		file.open(filename, ios::binary | ios::out | ios::in);
		if (!file)
		{
			cout << "文件打开失败" << endl;
			exit(0);
		}
		file.seekp(pos, ios::beg);
		file.write((char*)&user, sizeof(User));
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool UserDao::deleteUser(int id)
{
	bool found;
	User data = findUserById(id, found);
	if (found)
	{
		data.setDelete();
		return updateUser(id, data);
	}
	else
	{
		return false;
	}
}

User UserDao::findUserById(int id, bool &found)
{
	User data;
	int pos = getPosition(id);
	if (pos != -1)
	{
		found = true;
		file.open(filename, ios::binary | ios::in);
		file.seekg(pos, ios::beg);
		file.read((char*)&data, sizeof(User));
		file.close();
	}
	else
	{
		found = false;
	}
	return data;
}


User UserDao::findUserByName(const string &name, bool &found)
{
	User data;
	file.open(filename, ios::binary | ios::in);
	file.seekg(ios::beg);
	found = false;
	while (!file.eof())
	{
		file.read((char*)&data,sizeof(User));
		if (data.getName() == name)
		{
			found = true;
			break;
		}
	}
	file.close();
	return data;
}

vector<User> UserDao::findAllUser()
{
	vector<User> dataList;
	file.open(filename, ios::binary | ios::in);
	file.seekg(sizeof(int), ios::beg);
	while (!file.eof())
	{
		User data;
		file.read((char*)&data, sizeof(User));
		if (file.gcount() != 0)
		{
			dataList.push_back(data);
		}
	}
	file.close();
	return dataList;
}