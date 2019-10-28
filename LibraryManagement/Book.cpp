#include "Book.h"
#include <cstring>


Book::Book()
{
}


Book::~Book()
{
}

int Book::getId() 
{
	return this->id;
}

void Book::setId(const int id) 
{
	this->id = id;
}

int Book::getTypeId()
{
	return this->typeId;
}

void Book::setTypeId(const int typeId)
{
	this->typeId = typeId;
}

string Book::getName()
{
	return string(this->name);
}

void Book::setName(const string &name)
{
	strcpy(this->name, name.c_str());
}

string Book::getAuthor()
{
	return string(this->author);
}

void Book::setAuthor(const string &author)
{
	strcpy(this->author, author.c_str());
}

string Book::getPublisher()
{
	return string(this->publisher);
}

void Book::setPublisher(const string &publisher)
{
	strcpy(this->publisher, publisher.c_str());
}

string Book::getISBN()
{
	return string(this->ISBN);

}

void Book::setISBN(const string &ISBN)
{
	strcpy(this->ISBN, ISBN.c_str());
}

double Book::getPrice()
{
	return this->price;
}

void Book::setPrice(const double price)
{
	this->price = price;
}

int Book::getQuantity()
{
	return this->quantity;
}

void Book::setQuantity(const int quantity)
{
	this->quantity = quantity;
}

Book::BookStatus Book::getStatus()
{
	return this->status;
}

void Book::setStatus(const Book::BookStatus status)
{
	this->status = status;
}

void Book::setDelete()
{
	this->status = DELETED;
}

bool Book::isDelete()
{
	if (this->status = DELETED)
	{
		return true;
	}
	return false;
}