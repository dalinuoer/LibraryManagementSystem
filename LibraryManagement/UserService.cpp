#include "UserService.h"
#include "User.h"
#include "UserDao.h"


UserService::UserService():userDao("data/User.dat")
{
}

bool UserService::addUser(const User &user)
{	
	return userDao.insertUser(user);
}

bool UserService::delUser(int id)
{
	return userDao.deleteUser(id);
}

vector<User> UserService::findAllUser()
{
	return userDao.findAllUser();
}

int UserService::changeUserInfo(int userid, const User &user)
{
	return userDao.updateUser(userid, user);
}

User UserService::findUserById(int id, bool &found)
{
	return userDao.findUserById(id, found);
}

User UserService::findUserByName(string username, bool &found)
{
	return userDao.findUserByName(username, found);
}




