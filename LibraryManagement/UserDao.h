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
	bool updateUser(const string &id, const User &user);
	bool deleteUser(const string &id);
	User findUserById(const string &id, bool &found);
	User findUserByName(const string &name, bool &found);
	vector<User> findAllUser();

private:
	int getPosition(const string &id);
	Dao<User> dao;
	string filename;
	fstream file;
};

