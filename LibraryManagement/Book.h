#pragma once
#include <string>

using namespace std;

class Book
{
public:
	static enum BookStatus
	{
		NORMAL,
		DELETED,
	};

public:
	Book();
	~Book();
	int getId();
	void setId(const int id);
	string getName();
	void setName(const string &name);
	string getPublisher();
	void setPublisher(const string &publisher);
	string getISBN();
	void setISBN(const string &ISBN);
	double getPrice();
	void setPrice(const double price);
	int getQuantity();
	void setQuantity(const int quantity);
	BookStatus getStatus();
	void setStatus(const BookStatus status);

private:
	int id;
	int typeId;
	char name[40];
	char author[40];
	char publisher[40];
	char ISBN[13];
	double price;
	int quantity;
	BookStatus status;
};

