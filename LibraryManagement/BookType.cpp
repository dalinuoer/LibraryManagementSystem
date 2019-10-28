#include "BookType.h"



BookType::BookType()
{
}


BookType::~BookType()
{
}

int BookType::getId()
{
	return this->id;
}

void BookType::setId(const int id)
{
	this->id = id;
}

string BookType::getName()
{
	return string(this->name);
}

void BookType::setName(const string &name)
{
	strcpy(this->name, name.c_str());
}

void BookType::setDelete()
{
	this->status = DELETED;
}

bool BookType::isDelete()
{
	if (this->status = DELETED)
	{
		return true;
	}
	return false;
}