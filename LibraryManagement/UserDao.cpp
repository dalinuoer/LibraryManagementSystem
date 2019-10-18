#include "UserDao.h"
#include <iostream>

using namespace std;

UserDao::UserDao(string filename) : dao(filename)
{
	this->filename = filename;
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
	return User();
}

vector<User> UserDao::findAllUser()
{
	vector<User> userList;
	file.open(filename, ios::binary | ios::in);
	file.seekg(ios::beg);
	while (!file.eof())
	{
		User user;
		file.read((char*)&user, sizeof(User));
		if (file.gcount() != 0)
		{
			userList.push_back(user);
		}
	}
	file.close();
	return userList;
}