#include "UserService.h"
#include "User.h"
#include "UserDao.h"


UserService::UserService() :userDao("data/User.dat")
{
}

int UserService::addUser(const User &user)
{
	bool found;
	string id = user.getId();
	userDao.findUserById(id,found);
	if (found)
	{
		return UserService::USER_ALREADAY_EXIST;
	}
	else
	{
		if (userDao.insertUser(user) != -1)
		{
            return UserService::SUCCESS;
		}
		else
		{
            return UserService::ERROR;
		}
	}

}

int UserService::delUser(const string &id)
{
	bool found;
	userDao.findUserById(id, found);
	if (found)
	{
		if (userDao.deleteUser(id))
		{
            return UserService::SUCCESS;
		}
		else
		{
            return UserService::ERROR;
		}
	}
	else
	{
		return UserService::USER_NOT_FOUND;
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
		if (userDao.updateUser(id,user))
		{
            return UserService::SUCCESS;
		}
		else
		{
            return UserService::ERROR;
		}
	}
	else
	{
		return UserService::USER_NOT_FOUND;
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
