#include "UserService.h"
#include "User.h"
#include "UserDao.h"


UserService::UserService() :userDao("data/User.dat")
{
}

bool UserService::addUser(const User &user)
{
	bool found;
	string id = user.getId();
	userDao.findUserById(id,found);
	if (found) 
	{
		return false;
	}
	else
	{
		return userDao.insertUser(user);
	}

}

bool UserService::delUser(const string &id)
{
	bool found;
	userDao.findUserById(id, found);
	if (found)
	{
		return userDao.deleteUser(id);
	}
	else
	{
		return false;
	}
}

vector<User> UserService::findAllUser()
{
	return userDao.findAllUser();
}

int UserService::changeUserInfo(const string &id, const User &user)
{
	bool found;
	userDao.findUserById(id, found);
	if (found)
	{
		return userDao.updateUser(id,user);
	}
	else
	{
		return false;
	}
}

User UserService::findUserById(const string &id, bool &found)
{
	return userDao.findUserById(id, found);
}

User UserService::findUserByName(string username, bool &found)
{
	return userDao.findUserByName(username, found);
}