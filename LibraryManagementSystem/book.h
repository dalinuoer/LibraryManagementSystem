#pragma once
#include <string>
class book
{
private:
	int id;
	char name[40];
	char author[40];
	char publisher[40];
	char ISBN[13];
	double price;
public:
	book()
	{
	}

	virtual ~book()
	{
	}

	int getId()
	{
		return id;
	}

	void setId(int newId)
	{
		id = newId;
	}

	char* getName()
	{
		return name;
	}

	void setName(char* newName)
	{
		strcpy(name, newName);
	}

	char* getAuthor()
	{
		return author;
	}

	void setAuthor(char* newAuthor)
	{
		strcpy(author, newAuthor);
	}

	char* getPublisher()
	{
		return publisher;
	}

	void setPublisher(char* newPublisher)
	{
		 strcpy(publisher, newPublisher);
	}

	char* getISBN()
	{
		return ISBN;
	}

	void setISBN(char* newISBN)
	{
		strcpy(ISBN, newISBN);
	}

	double getPrice()
	{
		return price;
	}

	void setPrice(double newPrice)
	{
		price = newPrice;
	}
};

