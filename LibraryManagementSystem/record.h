#pragma once
#include <string>
class record
{
private:
	int id;
	int userId;
	int bookId;
	std::string date;
	int duration;
	std::string returnDate;
public:
	record()
	{
	}

	~record()
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

	int getUserId()
	{
		return userId;
	}

	void setUserId(int newUserId)
	{
		userId = newUserId;
	}

	int getBookId()
	{
		return bookId;
	}

	void setBookId(int newBookId)
	{
		bookId = newBookId;
	}

	std::string getDate()
	{
		return date;
	}

	void setDate(std::string newDate)
	{
		date = newDate;
	}

	int getDuration()
	{
		return duration;
	}

	void setDuration(int newDuration)
	{
		duration = newDuration;
	}

	std::string getReturnDate()
	{
		return returnDate;
	}

	void setReturnDate(std::string newReturnDate)
	{
		returnDate = newReturnDate;
	}
};

