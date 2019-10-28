#include "UserService.h"
#include "User.h"
#include "UserDao.h"


UserService::UserService() :userDao("data/User.dat")
{
}

bool UserService::addUser(const User &user)
{
	bool found;
	int id = user.getId();
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

bool UserService::delUser(int id)
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

int UserService::changeUserInfo(int userid, const User &user)
{
	bool found;
	userDao.findUserById(userid, found);
	if (found)
	{
		return userDao.updateUser(userid,user);
	}
	else
	{
		return false;
	}
}

User UserService::findUserById(int id, bool &found)
{
	return userDao.findUserById(id, found);
}

User UserService::findUserByName(string username, bool &found)
{
	return userDao.findUserByName(username, found);
}