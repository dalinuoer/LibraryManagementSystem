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

class RecordService {
public:		
	RecordService();
	int borrowBook(int userId, int AbookId);
	int renewBook(int recordId, int duration);
	bool returnBook(int recordId);
	bool returnBook(int userid, int bookid);
	Record findRecordByUserIdAndBookId(int userid,int bookid,bool &found);
	vector<Record>findAllRecord();
	vector<Record>findRecordByBookId(int bookId);
	vector<Record>findRecordByUserId(int userId);

private:
	BookDao bookDao;
	ABookDao aBookDao;
	UserDao userDao;
	RecordDao recordDao;
};