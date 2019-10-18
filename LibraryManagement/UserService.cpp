#include "UserService.h"
#include <string>
#include <vector>
#include "User.h"
using namespace std;

UserDao userDao = new UserDao();

bool UsersService::addUser(User user)
{
	User u = userDao.findByName(user.getName());
	if (u != NULL) { // 如果要添加的name已经存在
		return -1;
	}
	return userDao.addUser(user);

}

bool UsersService::delUser(int id)
{
	return userDao.delUser(id);

}

vector<User> UsersService::findAllUser()
{
	return userDao.findAllUser();
}

bool UsersService::changeUserinfo(int userid, User user)
{
	return userDao.updateUser(userid, user);
}

