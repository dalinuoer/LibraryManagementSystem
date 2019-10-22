#pragma once
#include <string>

using namespace std;

class Record
{
public:
	static enum RecordStatus
	{
		NORMAL,
		EXCEED,
		RETURNED,
	};

public:
	Record();
	~Record();
	int getId();
	void setId(const int id);
	int getUserId();
	void setUserId(const int userId);
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

private:
	int id;
	int userId;
	int bookId;
	int aBookId;
	char date[40];
	int duration;
	char returnDate[40];
	RecordStatus status;
};

