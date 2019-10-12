#pragma once
#include <string>

using namespace std;

class User
{
public:
	static enum UserType
	{
		STUDENT,
		TEACHER,
	};
	static enum UserStatus
	{
		NORMAL,
		DELETED,
		FULL,
	};

public:
	User();
	~User();
	int getId();
	void setId(const int id);
	string getName();
	void setName(const string &name);
	UserType getType();
	void setType(const UserType type);
	UserStatus getStatus();
	void setStatus(const UserStatus status);

private:
	int id;
	char name[40];
	UserType type;
	UserStatus status;
};

