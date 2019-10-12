#pragma once
class ABook
{
public:
	static enum ABookStatus
	{
		NORMAL,
		DELETED,
		BORROWED,
	};

public:
	ABook();
	~ABook();
	int getId();
	void setId(const int id);
	int getBookId();
	void setBookId(const int bookId);
	ABookStatus getStatus();
	void setStatus(const ABookStatus status);

private:
	int id;
	int bookId;
	ABookStatus status;  //µ±Ç°Êé×´Ì¬
};