#include "User.h"
#include <cstring>


User::User()
{
}


User::~User()
{
}

int User::getId()
{
	return this->id;
}

void User::setId(const int id)
{
	this->id = id;
}

string User::getName()
{
	return string(this->name);
}

void User::setName(const string &name)
{
	strcpy(this->name, name.c_str());
}

User::UserType User::getType()
{
	return this->type;
}

void User::setType(const User::UserType type)
{
	this->type = type;
}

User::UserStatus User::getStatus()
{
	return this->status;
}

void User::setStatus(const User::UserStatus status)
{
	this->status = status;
}

void User::setDelete()
{
	this->status = DELETED;
}

bool User::isDelete()
{
	return this->status == UserStatus::DELETED;
}