#pragma once
#include <cstring>
#include <string>

using namespace std;

class User
{
public:
	static enum UserType
	{
		STUDENT = 0,
		TEACHER,
	};
	static enum UserStatus
	{
		NORMAL = 0,
		DELETED,
		FULL,
	};

public:
	User();
	~User();
	string getId() const;
	void setId(const string &id);
	string getName();
	void setName(const string &name);
	UserType getType();
	void setType(const UserType type);
	UserStatus getStatus();
	void setStatus(const UserStatus status);
	void setDelete();
	bool isDelete() const;

private:
	char id[20];
	char name[40];
	UserType type;
	UserStatus status;
};

