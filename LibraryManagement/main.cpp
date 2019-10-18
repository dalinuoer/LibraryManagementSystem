#include <iostream>
#include <fstream>
#include "User.h"
#include "Book.h"
#include "Record.h"
#include "UserDao.h"

using namespace std;

int main()
{
	User user;
	user.setId(1);
	user.setName("Hi");
	user.setType(User::STUDENT);
	user.setStatus(User::NORMAL);
	
	
	UserDao userDao("data/User.dat");
	userDao.insertUser(user);

	user.setId(2);
	user.setName("Hello");
	userDao.insertUser(user);

	user.setId(3);
	user.setName("World");
	userDao.insertUser(user);

	user.setName("Hey");
	userDao.updateUser(3, user);

	return 0;
}