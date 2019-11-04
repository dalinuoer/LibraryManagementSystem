#pragma once
#include "ABook.h"
#include "ABookDao.h"
#include "Book.h"
#include "BookDao.h"
#include "User.h"
#include "UserDao.h"
#include "Record.h"
#include "RecordDao.h"
#include <vector>
#include"RecordVo.h"
class RecordService {

public:
	const static int SUCCESS = 0;				//³É¹¦
	const static int USER_NOT_FOUND = -1;
	const static int ABOOK_NOT_FOUND = -2;
	const static int ERROR = -3;
	const static int RECORD_NOT_FOUND = -4;

	
public:		
	RecordService();
	~RecordService();
	int borrowBook(const string &userId, int aBookId);
	int renewBook(int recordId, int duration);
	int returnBook(int recordId);
	int returnBook(const string &userId, int bookid);
	RecordVo findRecordByUserIdAndBookId(const string &userId, int bookid, bool &found);
	vector<RecordVo>findAllRecord();
	vector<RecordVo>findRecordByBookId(int bookId);
	vector<RecordVo>findRecordByUserId(const string &userId);
	
private:
	BookDao bookDao;
	ABookDao aBookDao;
	UserDao userDao;
	RecordDao recordDao;
};