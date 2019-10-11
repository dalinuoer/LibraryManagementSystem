#pragma once
#include <string>
class user
{
private:
	int id;
	char name[40];
	enum userType
	{
		STUDENT, 
		TEACHER,
	};
	userType type;
public:
	user()
	{
	}

	virtual ~user()
	{
	}

	int getId()
	{
		return id;
	}

	void setId(int newId)
	{
		id = newId;
	}

	char* getName()
	{
		return name;
	}

	void setName(char* newName)
	{
		strcpy(name, newName);
	}
	
	userType getType()
	{
		return type;
	}

	void setType(userType newType)
	{
		type = newType;
	}
};

