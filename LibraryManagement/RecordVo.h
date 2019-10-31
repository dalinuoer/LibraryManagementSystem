#pragma once
#include <cstring>
#include <string>
#include "Record.h"

using namespace std;

class RecordVo : public Record
{
public:
	void setUserName(const string &name);
	void setBookName(const string &name);
	void setAuthor(const string &author);
	void setPublisher(const string &publisher);
	string getUserName();
	string getBookName();
	string getAuthor();
	string getPublisher();

private:
	//User�ֶ�
	string userName;
	//Book�ֶ�
	string bookName;
	string author;
	string publisher;
};