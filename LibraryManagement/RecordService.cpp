#include "RecordService.h"
#include <ctime>
#include <sstream>

string getDate()
{
	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	tm *ltm = localtime(&now);

	stringstream ss;
	ss << 1900 + ltm->tm_year << "-";
	ss << 1 + ltm->tm_mon << "-";
	ss << ltm->tm_mday;
	return ss.str();
}


RecordService::RecordService() :bookDao("data/Book.dat"), userDao("data/User.dat"),
recordDao("data/Record.dat"), aBookDao("data/Abook.dat")
{
}

RecordService::~RecordService()
{
}

bool RecordService::borrowBook(const string &userId, int aBookId)
{
	//检测用户是否存在
	bool foundU;
	User user = userDao.findUserById(userId, foundU);
	if (!foundU)
	{
		return false;													//未找到此用户 -1
	}

	//检测书是否存在（书应该存在，因为上层传输来的是bookId 是经过其他途径查询获知）
	bool foundB;
	ABook abook = aBookDao.findABookById(aBookId, foundB);
	if (!foundB)
	{
		return false;													//未找到书		-2
	}

	//检验书是否被删除													//书已被删除    -3
	if (abook.getStatus() == ABook::DELETED)
	{
		return false;
	}


	//检测该书是否还有剩余	
	Book book = bookDao.findBookById(abook.getBookId(), foundB);
	if (book.getQuantity() == 0)
	{
		return false;											//书无剩余		-4
	}
	//有剩余继续进行借阅操作
	Record record;
	record.setBookId(aBookId);
	record.setUserId(userId);
	record.setStatus(Record::NORMAL);
	record.setId(0);
	record.setDate(getDate());												//《========================设置各种时间=======================================
	record.setDuration(15);
	record.setReturnDate("未归还");
	book.setQuantity(book.getQuantity() - 1);
	abook.setStatus(ABook::BORROWED);
	if (recordDao.insertRecord(record) != -1)
	{
		return true;												//借书成功		0
	}

	return false;														//其他错误情况导致设置失败 -5
}

bool RecordService::renewBook(int recordId, int duration)
{
	//搜索该记录
	bool found;
	Record record = recordDao.findRecordById(recordId, found);
	if (!found)
	{
		return false;														//未找到该记录
	}
	if (duration <= 0)
	{
		return false;														//延长时间应为正整数 
	}
	//更新时长
	if (record.getStatus() == Record::EXCEED)
	{
		record.setStatus(Record::NORMAL);
	}
	record.setDuration(record.getDuration() + duration);					//设置新借阅时长

	if (recordDao.updateRecord(recordId, record))
	{
		return true;														//还书成功
	}
	return false;															//其他出错情况														
}

bool  RecordService::returnBook(int recordId)
{
	/*Mission:	 Abook状态变为NORMAL 记录状态变为RETURNED*/
	//检测用户是否存在
	bool found;
	Record record = recordDao.findRecordById(recordId, found);
	if (!found)
	{
		return false;
	}
	record.setStatus(Record::RETURNED);
	record.setReturnDate(getDate());
	recordDao.updateRecord(recordId, record);

	ABook aBook = aBookDao.findABookById(record.getABookId(), found);
	aBook.setStatus(ABook::NORMAL);
	aBookDao.updateABook(aBook.getId(), aBook);

	Book book = bookDao.findBookById(record.getBookId(), found);
	book.setQuantity(book.getQuantity() + 1);
	bookDao.updateBook(book.getId(), book);

	return true;
}

bool RecordService::returnBook(const string &userId, int bookid)
{
	bool found;
	Record record = recordDao.findRecordByUserIdAndBookId(userId, bookid, found);
	if (!found)
	{
		return false;
	}
	record.setStatus(Record::RETURNED);
	record.setReturnDate(getDate());
	recordDao.updateRecord(record.getId(), record);

	ABook aBook = aBookDao.findABookById(record.getABookId(), found);
	aBook.setStatus(ABook::NORMAL);
	aBookDao.updateABook(aBook.getId(), aBook);

	Book book = bookDao.findBookById(bookid, found);
	book.setQuantity(book.getQuantity() + 1);
	bookDao.updateBook(book.getId(), book);

	
	return true;
}

RecordVo RecordService::findRecordByUserIdAndBookId(const string &userid, int bookid, bool &found)
{
	Record record = recordDao.findRecordByUserIdAndBookId(userid, bookid, found);
	Book book = bookDao.findBookById(bookid, found);
	User user = userDao.findUserById(userid, found);
	RecordVo vo;
	vo.setUserId(userid);
	vo.setBookId(bookid);
	//RecordVo record字段
	vo.setId(record.getId());
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
		vo.setId(record.getId());
		vo.setABookId(record.getBookId());
		vo.setBookId(record.getABookId());
		vo.setDate(record.getDate());
		vo.setDuration(record.getDuration());
		vo.setReturnDate(record.getReturnDate());
		vo.setStatus(record.getStatus());
		//RecordVo user字段
		vo.setUserName(user.getName());
		//RecordVo book字段
		vo.setBookName(book.getName());
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
		vo.setId(record.getId());
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

vector<RecordVo> RecordService::findRecordByUserId(const string &userId)
{
	vector<Record> list = recordDao.findRecordByUserId(userId);
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
		vo.setId(record.getId());
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