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
	int borrowBook(int userId, int AbookId);
	int renewBook(int recordId, int duration);
	bool returnBook(int recordId);
	bool returnBook(int userid, int bookid);
	RecordVo findRecordByUserIdAndBookId(int userid,int bookid,bool &found);
	vector<RecordVo>findAllRecord();
	vector<RecordVo>findRecordByBookId(int bookId);
	vector<RecordVo>findRecordByUserId(int userId);
	
private:
	BookDao bookDao;
	ABookDao aBookDao;
	UserDao userDao;
	RecordDao recordDao;
};