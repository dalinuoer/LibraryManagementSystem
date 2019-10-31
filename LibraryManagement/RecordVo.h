#pragma once
#include <cstring>
#include <string>
#include "Record.h"

using namespace std;

class RecordVo : public Record
{
public:
	void setUserName(const string &name);
	void setUserId(const int id);

	void setBookName(const string &name);
	void setAuthor(const string &author);
	void setPublisher(const string &publisher);

	string getDate();
	int getDuration();
	string getReturnDate();
	
	string getUserName();
	int getUserId();

	string getBookName();
	string getAuthor();
	string getPublisher();

private:
	//Record�ֶ�
	string date;
	int duration;
	string returnDate;
	//Record����ʾ�ֶ�
	int recordId;
	int bookId;
	int aBookId;
	//int userId;
	Record::RecordStatus status;
	//User�ֶ�
	int userId;
	string userName;
	//Book�ֶ�
	string bookName;
	string author;
	string publisher;
};