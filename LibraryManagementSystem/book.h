#pragma once
#include <string>
class book
{
private:
	int id;
	std::string name;
	std::string author;
	std::string publisher;
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

	std::string getName()
	{
		return name;
	}

	void setName(std::string newName)
	{
		name = newName;
	}

	std::string getAuthor()
	{
		return author;
	}

	void setAuthor(std::string newAuthor)
	{
		author = newAuthor;
	}

	std::string getPublisher()
	{
		return publisher;
	}

	void setPublisher(std::string newPublisher)
	{
		publisher = newPublisher;
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

