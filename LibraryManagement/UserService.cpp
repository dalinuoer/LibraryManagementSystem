#include "UserService.h"
#include <string>
#include <vector>
#include <iostream>
#include "User.h"
#include"UserDao.h"
//#include"RecordService.h"
using namespace std;

UserDao* userDao = new UserDao("filename.txt");

bool UsersService::addUser(User user)
{
	User u = userDao->findUserById(user.getId(), found);
	if (u != NULL) { // 如果要添加的name已经存在
		return -1;
	}
	return userDao->insertUser(user);

}

bool UsersService::delUser(int id)
{
	return userDao->deleteUser(id);

}

vector<User> UsersService::findAllUser()
{
	return userDao->findAllUser();
}

bool UsersService::changeUserinfo(int userid, User user)
{
	return userDao->updateUser(userid, user);
}




