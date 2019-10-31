#pragma once
#include <string>
#include <vector>
#include "UserDao.h"
#include "User.h"

using namespace std;

class UserService 
{
public:
	UserService();
	bool addUser(const User &user);
	bool delUser(const string &id);
	int changeUserInfo(const string &id, const User &user);
	User findUserById(const string &id, bool &found);
	User findUserByName(string username, bool &found);
	vector<User> findAllUser();

private:
	UserDao userDao;
};