#pragma once
#include <cstring>
#include <string>

using namespace std;

class BookType
{
public:
	static enum BookTypeStatus {
		DELETED,
	};

public:
	BookType();
	~BookType();
	int getId();
	void setId(const int id);
	string getName();
	void setName(const string &name);
	void setDelete();
	bool isDelete();

private:
	int id;
	char name[40];
	BookTypeStatus status;
};

