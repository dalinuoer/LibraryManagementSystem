#include "ABookVo.h"

ABookVo::ABookVo(Book &book, ABook &aBook)
{
	this->setId(aBook.getId());
	this->setBookId(aBook.getBookId());
	this->bookName = book.getName();
	this->author = book.getAuthor();
	this->publisher = book.getPublisher();
}


ABookVo::~ABookVo()
{
}

string ABookVo::getBookName()
{
	return this->bookName;
}

void ABookVo::setBookName(const string &bookName)
{
	this->bookName = bookName;
}


string ABookVo::getAuthor()
{
	return this->author;
}

void ABookVo::setAuthor(const string &author)
{
	this->author = author;
}

string ABookVo::getPublisher()
{
	return this->publisher;
}

void ABookVo::setPublisher(const string &publisher)
{
	this->publisher = publisher;
}
