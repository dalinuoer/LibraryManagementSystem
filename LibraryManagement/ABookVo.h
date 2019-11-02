#pragma once
#include "Book.h"
#include "ABook.h"

class ABookVo : public ABook
{
public:
	ABookVo(Book &book, ABook &aBook);
	~ABookVo();
	string getBookName();
	void setBookName(const string &bookName);
	string getAuthor();
	void setAuthor(const string &author);
	string getPublisher();
	void setPublisher(const string &publisher);

private:
	string bookName;
	string author;
	string publisher;
};

