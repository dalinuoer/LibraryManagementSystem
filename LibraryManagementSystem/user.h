#pragma once
#include <string>
class user
{
private:
	int id;
	std::string name;
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

	std::string getName()
	{
		return name;
	}

	void setName(std::string newName)
	{
		name = newName;
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

