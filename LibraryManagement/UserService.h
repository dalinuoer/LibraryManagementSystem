#pragma once
#include <string>
#include <vector>
#include "UserDao.h"
#include "User.h"

using namespace std;

class UserService
{
public:
	const static int USER_NOT_FOUND  = 1;
	const static int USER_ALREADAY_EXIST = 2;
	const static int ERROR = 3;
	const static int SUCCESS = 4;

	UserService();
	int addUser(const User &user);
	int delUser(const string &id);
	int changeUserInfo(const string &id, const User &user);
	User findUserById(const string &id, bool &found);
	User findUserByName(string username, bool &found);
	vector<User> findAllUser();

private:
	UserDao userDao;
};
