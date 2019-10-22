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

using namespace std;

class RecordService {
public:	
	
	int borrowBook(int userId, int AbookId);
	int renewBook(int recordId, int duration);
	int returnBook(int recordId);
	vector<Record>findAllRecord();
	vector<Record>findRecordByBookId(int bookId);
	vector<Record>findRecordByUserId(int userId);

private:
	BookDao bookDao;
	UserDao userDao;
	ABookDao aBookDao;
	RecordDao recordDao;
};