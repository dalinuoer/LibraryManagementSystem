#pragma once
#include <string>

using namespace std;

class BookType
{
public:
	BookType();
	~BookType();
	int getId();
	void setId(const int id);
	string getName();
	void setName(const string &name);

private:
	int id;
	char name[40];
};

