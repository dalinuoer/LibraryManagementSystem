#pragma once
#include <string>
#include <vector>
#include "User.h"
using namespace std;

class UsersService {
public:
	bool addUser(User user);
	bool delUser(int id);
	vector<User> findAllUser();
	bool changeUserinfo(int userid, User user);

};