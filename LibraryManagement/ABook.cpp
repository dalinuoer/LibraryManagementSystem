#include "ABook.h"


ABook::ABook()
{
}


ABook::~ABook()
{
}

int ABook::getId()
{
	return this->id;
}

void ABook::setId(const int id)
{
	this->id = id;
}

int ABook::getBookId()
{
	return this->bookId;
}

void ABook::setBookId(const int bookId)
{
	this->bookId = bookId;
}

ABook::ABookStatus ABook::getStatus()
{
	return this->status;
}

void ABook::setStatus(const ABookStatus status)
{
	this->status = status;
}