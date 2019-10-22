#pragma once
#include <string>
#include <vector>
#include "User.h"

class UserService 
{
public:
	UserService();
	bool addUser(const User &user);
	bool delUser(int id);
	int changeUserInfo(int userid, const User &user);
	User findUserById(int id, bool &found);
	vector<User> findAllUser();

private:
	UserDao userDao;
};