#pragma once
#include<string>
#include"Record.h"
using namespace std;
class RecordVo {

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
	Record:: RecordStatus status;
	//User�ֶ�
	int userId;
	string userName;
	//Book�ֶ�
	string bookName;
	string author;
	string publisher;
	

public:
	void setDate(const string &date);
	void setDuration(const int duration);
	void setReturnDate(const string &returnDate);

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
	//������ʾ��Record�ֶ�
	void setRecordId(const int id);
	void setBookId(const int id);
	void setABookId(const int id);
	void setStatus(const Record::RecordStatus status);

	int getRecordId();
	int getBookId();
	int getABookId();
	Record::RecordStatus getStatus();

};