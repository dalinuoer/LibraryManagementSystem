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
	bool delUser(int id);
	int changeUserInfo(int userid, const User &user);
	User findUserById(int id, bool &found);
	User findUserByName(string username, bool &found);
	vector<User> findAllUser();

private:
	UserDao userDao;
};