#pragma once
class ABook
{
public:
	static enum ABookStatus
	{
		NORMAL = 0,
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
	void setDelete();
	bool isDelete();

private:
	int id;
	int bookId;
	ABookStatus status;  //µ±Ç°Êé×´Ì¬
};