#include "RecordVo.h"

void RecordVo::setDate(const string & date)
{
	this->date = date;
}

void RecordVo::setDuration(const int duration)
{
	this->duration = duration;
}

void RecordVo::setReturnDate(const string & returnDate)
{
	this->returnDate = returnDate;
}

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

void RecordVo::setRecordId(const int id)
{
	this->recordId = id;
}

void RecordVo::setBookId(const int id)
{
	this->bookId = id;
}

void RecordVo::setABookId(const int id)
{
	this->bookId = id;
}

void RecordVo::setStatus(const Record::RecordStatus status)
{
	this->status = status;
}

int RecordVo::getRecordId()
{
	return this->recordId;
}

int RecordVo::getBookId()
{
	return this->bookId;
}

int RecordVo::getABookId()
{
	return this->bookId;
}

Record::RecordStatus RecordVo::getStatus()
{
	return this->status;
}

