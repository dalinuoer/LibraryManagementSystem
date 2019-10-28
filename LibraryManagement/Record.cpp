#include "Record.h"



Record::Record()
{
}


Record::~Record()
{
}

int Record::getId()
{
	return this->id;
}

void Record::setId(const int id)
{
	this->id = id;
}

int Record::getUserId()
{
	return this->userId;
}

void Record::setUserId(const int userId)
{
	this->userId = userId;
}

int Record::getBookId()
{
	return this->bookId;
}

void Record::setBookId(const int bookId)
{
	this->bookId = bookId;
}

int Record::getABookId()
{
	return this->aBookId;
}

void Record::setABookId(int aBookId)
{
	this->aBookId = aBookId;
}

string Record::getDate()
{
	return string(this->date);
}

void Record::setDate(const string &date)
{
	strcpy(this->date, date.c_str());
}

int Record::getDuration()
{
	return this->duration;
}

void Record::setDuration(const int duration)
{
	this->duration = duration;
}

string Record::getReturnDate()
{
	return string(this->returnDate);
}

void Record::setReturnDate(const string &returnDate)
{
	strcpy(this->returnDate,returnDate.c_str());
}

Record::RecordStatus Record::getStatus()
{
	return this->status;
}

void Record::setStatus(const Record::RecordStatus status)
{
	this->status = status;
}

void Record::setDelete()
{
	this->status = DELETED;
}

bool Record::isDelete()
{
	if (this->status = DELETED)
	{
		return true;
	}
	return false;
}