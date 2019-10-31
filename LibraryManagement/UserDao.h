#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "User.h"
#include "Dao.hpp"

using namespace std;

class UserDao
{
public:
	UserDao(const string &filename);
	~UserDao();
	bool insertUser(const User &user);
	bool updateUser(int id, const User &user);
	bool deleteUser(int id);
	User findUserById(int id, bool &found);
	User findUserByName(const string &name, bool &found);
	vector<User> findAllUser();

private:
	int getPosition(int id);
	Dao<User> dao;
	string filename;
	fstream file;
};

