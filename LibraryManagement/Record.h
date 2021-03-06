#pragma once
#include <cstring>
#include <string>

using namespace std;

class Record
{
public:
	static enum RecordStatus
	{
		NORMAL = 0,
		EXCEED,
		RETURNED,
		DELETED,
	};

public:
	Record();
	~Record();
	int getId();
	void setId(const int id);
	string getUserId();
	void setUserId(const string &userId);
	int getBookId();
	void setBookId(const int bookId);
	int getABookId();
	void setABookId(int aBookId);
	string getDate();
	void setDate(const string &date);
	int getDuration();
	void setDuration(const int duration);
	string getReturnDate();
	void setReturnDate(const string &returnDate);
	RecordStatus getStatus();
	void setStatus(const RecordStatus status);
	void setDelete();
	bool isDelete();

private:
	int id;
	char userId[20];
	int bookId;
	int aBookId;
	char date[40];
	int duration;
	char returnDate[40];
	RecordStatus status;
};

