#include "RecordVo.h"

void RecordVo::setUserName(const string & name)
{
	this->userName = name;
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

string RecordVo::getUserName()
{
	return this->userName;
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
