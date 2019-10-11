#pragma once
#include <string>
class record
{
private:
	int id;
	int userId;
	int bookId;
	char date[40];
	int duration;
	char returnDate[40];
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

	char* getDate()
	{
		return date;
	}

	void setDate(char* newDate)
	{
		strcpy(date, newDate);
	}

	int getDuration()
	{
		return duration;
	}

	void setDuration(int newDuration)
	{
		duration = newDuration;
	}

	char* getReturnDate()
	{
		return returnDate;
	}

	void setReturnDate(char* newReturnDate)
	{
		strcpy(returnDate, newReturnDate);
	}
};

