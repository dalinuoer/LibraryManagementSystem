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
	RecordService();
	~RecordService();
	bool borrowBook(const string &userId, int aBookId);
	bool renewBook(int recordId, int duration);
	bool returnBook(int recordId);
	bool returnBook(const string &userId, int bookid);
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