#include "RecordService.h"
#include<time.h>
#include<vector>


RecordService::RecordService() :bookDao("data/Book.dat"), userDao("data/User.dat"),
recordDao("data/Record.dat"), aBookDao("data/Abook.dat") 
{
}

RecordService::~RecordService()
{
}

int RecordService::borrowBook(int userId, int AbookId)
{
	//检测用户是否存在
	bool foundU;
	User user = userDao.findUserById(userId, foundU);
	if (!foundU)
	{
		return -1;													//未找到此用户 -1
	}

	//检测书是否存在（书应该存在，因为上层传输来的是bookId 是经过其他途径查询获知）
	bool foundB;
	ABook abook = aBookDao.findABookById(AbookId, foundB);
	if (!foundB)
	{
		return -2;													//未找到书		-2
	}

	//检验书是否被删除													//书已被删除    -3
	if (abook.getStatus() == ABook::DELETED) 
	{
		return -3;
	}


	//检测该书是否还有剩余	
	Book book = bookDao.findBookById(abook.getBookId(), foundB);
	if (book.getQuantity() == 0) 
	{
		return -4;													//书无剩余		-4
	}
	//有剩余继续进行借阅操作
	Record record;
	record.setBookId(AbookId);
	record.setUserId(userId);
	record.setStatus(Record::NORMAL);
	record.setId(0);
	record.setDate("");												//《========================设置各种时间=======================================
	record.setDuration(1);
	record.setReturnDate("未归还");
	book.setQuantity(book.getQuantity() - 1);
	abook.setStatus(ABook::BORROWED);
	if (recordDao.insertRecord(record)) 
	{
		return 0;													//借书成功		0
	}

	return -5;														//其他错误情况导致设置失败 -5

}

int RecordService::renewBook(int recordId, int duration)
{
	//搜索该记录
	bool found;
	Record record = recordDao.findRecordById(recordId, found);
	if (!found) 
	{
		return -1;														//未找到该记录
	}
	if (duration <= 0) 
	{
		return -2;														//延长时间应为正整数 
	}
	//更新时长
	if (record.getStatus() == Record::EXCEED)
	{
		record.setStatus(Record::NORMAL);
	}
	record.setDuration(record.getDuration() + duration);					//设置新借阅时长

	if (recordDao.updateRecord(recordId, record)) 
	{
		return 0;														//还书成功
	}
	return -3;															//其他出错情况														
}

bool  RecordService::returnBook(int recordId)
{
	/*Mission:	 Abook状态变为NORMAL 记录状态变为RETURNED*/
	//检测用户是否存在
	bool found;
	Record record = recordDao.findRecordById(recordId, found);

	ABook abook = aBookDao.findABookById(record.getABookId(), found);
	abook.setStatus(ABook::NORMAL);

	Book book = bookDao.findBookById(record.getBookId(), found);
	book.setQuantity(book.getQuantity() + 1);
	record.setStatus(Record::RETURNED);

	return true;
}

bool RecordService::returnBook(int userid, int bookid)
{
	bool found;
	Record record = recordDao.findRecordByUserIdAndBookId(userid, bookid, found);

	ABook abook = aBookDao.findABookById(record.getABookId(), found);
	abook.setStatus(ABook::NORMAL);

	Book book = bookDao.findBookById(bookid, found);
	book.setQuantity(book.getQuantity() + 1);

	record.setStatus(Record::RETURNED);
	return true;
}

RecordVo RecordService::findRecordByUserIdAndBookId(int userid, int bookid, bool &found)
{
	Record record = recordDao.findRecordByUserIdAndBookId(userid, bookid, found);
	Book book = bookDao.findBookById(bookid,found);
	User user = userDao.findUserById(userid, found);
	RecordVo vo;
	vo.setUserId(userid);
	vo.setBookId(bookid);
	//RecordVo record字段
	vo.setRecordId(record.getId());			
	vo.setABookId(record.getBookId());
	vo.setBookId(record.getABookId());
	vo.setDate(record.getDate());
	vo.setDuration(record.getDuration());
	vo.setReturnDate(record.getReturnDate());
	vo.setStatus(record.getStatus());
	//RecordVo user字段
	vo.setUserName(user.getName());
	//RecordVo book字段
	vo.setAuthor(book.getAuthor());
	vo.setPublisher(book.getPublisher());

	return vo;

}

vector<RecordVo> RecordService::findAllRecord()
{
	vector<Record> list = recordDao.findAllRecord();
	vector<RecordVo> voList;
	for (auto record : list)
	{
		bool found;
		Book book = bookDao.findBookById(record.getBookId(), found);
		User user = userDao.findUserById(record.getUserId(), found);
		RecordVo vo;
		vo.setUserId(record.getUserId());
		vo.setBookId(record.getBookId());
		//RecordVo record字段
		vo.setRecordId(record.getId());
		vo.setABookId(record.getBookId());
		vo.setBookId(record.getABookId());
		vo.setDate(record.getDate());
		vo.setDuration(record.getDuration());
		vo.setReturnDate(record.getReturnDate());
		vo.setStatus(record.getStatus());
		//RecordVo user字段
		vo.setUserName(user.getName());
		//RecordVo book字段
		vo.setAuthor(book.getAuthor());
		vo.setPublisher(book.getPublisher());

		voList.push_back(vo);
	}
	return voList;
}

vector<RecordVo> RecordService::findRecordByBookId(int bookId)
{
	vector<Record> list = recordDao.findRecordByBookId(bookId);
	vector<RecordVo> voList;
	for (auto record : list)
	{
		bool found;
		Book book = bookDao.findBookById(record.getBookId(), found);
		User user = userDao.findUserById(record.getUserId(), found);
		RecordVo vo;
		vo.setUserId(record.getUserId());
		vo.setBookId(record.getBookId());
		//RecordVo record字段
		vo.setRecordId(record.getId());
		vo.setABookId(record.getBookId());
		vo.setBookId(record.getABookId());
		vo.setDate(record.getDate());
		vo.setDuration(record.getDuration());
		vo.setReturnDate(record.getReturnDate());
		vo.setStatus(record.getStatus());
		//RecordVo user字段
		vo.setUserName(user.getName());
		//RecordVo book字段
		vo.setAuthor(book.getAuthor());
		vo.setPublisher(book.getPublisher());

		voList.push_back(vo);
	}
	return voList;
}

vector<RecordVo> RecordService::findRecordByUserId(int userId)
{
	vector<Record> list =  recordDao.findRecordByUserId(userId);
	vector<RecordVo> voList;
	for (auto record : list)
	{
		bool found;
		Book book = bookDao.findBookById(record.getBookId(), found);
		User user = userDao.findUserById(record.getUserId(), found);
		RecordVo vo;
		vo.setUserId(record.getUserId());
		vo.setBookId(record.getBookId());
		//RecordVo record字段
		vo.setRecordId(record.getId());
		vo.setABookId(record.getBookId());
		vo.setBookId(record.getABookId());
		vo.setDate(record.getDate());
		vo.setDuration(record.getDuration());
		vo.setReturnDate(record.getReturnDate());
		vo.setStatus(record.getStatus());
		//RecordVo user字段
		vo.setUserName(user.getName());
		//RecordVo book字段
		vo.setAuthor(book.getAuthor());
		vo.setPublisher(book.getPublisher());

		voList.push_back(vo);
	}
	return voList;
}