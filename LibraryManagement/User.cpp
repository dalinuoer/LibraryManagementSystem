#include "User.h"
#include <cstring>


User::User()
{
}


User::~User()
{
}

string User::getId() const
{
	return string(this->id);
}

void User::setId(const string &id)
{
	strcpy(this->id, id.c_str());
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

bool User::isDelete() const
{
	return this->status == UserStatus::DELETED;
}