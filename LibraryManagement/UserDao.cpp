#include "UserDao.h"
#include <iostream>

using namespace std;

UserDao::UserDao(const string &filename) : dao(filename), filename(filename)
{
}

UserDao::~UserDao()
{
}

bool UserDao::insertUser(const User &user)
{
	return dao.insert(user);
}

bool UserDao::updateUser(int id, const User &user)
{
	return dao.update(id, user);
}

bool UserDao::deleteUser(int id)
{
	return dao.del(id);
}

User UserDao::findUserById(int id, bool &found)
{
	User data = dao.findById(id, found);
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
	return dao.findAll();
}