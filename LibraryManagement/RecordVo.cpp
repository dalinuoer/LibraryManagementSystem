#include "RecordVo.h"

void RecordVo::setUserName(const string & name)
{
	this->userName = name;
}

void RecordVo::setUserId(const int id)
{
	this->userId = id;
}

void RecordVo::setBookName(const string & name)
{
	this->bookName = name;
}

void RecordVo::setAuthor(const string & author)
{
	this->author = author;
}

void RecordVo::setPublisher(const string & publisher)
{
	this->publisher = publisher;
}

string RecordVo::getDate()
{
	return this->date;
}

int RecordVo::getDuration()
{
	return this->duration;
}

string RecordVo::getReturnDate()
{
	return this->returnDate;
}

string RecordVo::getUserName()
{
	return this->userName;
}

int RecordVo::getUserId()
{
	return this->userId;
}

string RecordVo::getBookName()
{
	return this->bookName;
}
string RecordVo::getAuthor()
{
	return this->author;
}

string RecordVo::getPublisher()
{
	return this->publisher;
}
