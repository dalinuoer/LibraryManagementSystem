#include "RecordService.h"
#include<time.h>
#include<vector>


int RecordService::borrowBook(int userId, int AbookId)				
{
	//检测用户是否存在
	bool foundU;
	User user = userDao.findUserById(userId, foundU);
	if (!foundU) {
		return -1;													//未找到此用户 -1
	}
	
	//检测书是否存在（书应该存在，因为上层传输来的是bookId 是经过其他途径查询获知）
	bool foundB;
	ABook abook = aBookDao.findABookById(AbookId, foundB);
	if (!foundB) {
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
	record.setDuration(15);
	record.setReturnDate("");
	book.setQuantity(book.getQuantity() - 1);
	abook.setStatus(ABook::BORROWED);
	if (recordDao.insertRecord(record)) {
		return 0;													//借书成功		0
	}

	return -5;														//其他错误情况导致设置失败 -5

}
int RecordService::renewBook(int recordId, int duration)
{
	//搜索该记录
	bool found;
	Record record = recordDao.findRecordById(recordId, found);			//《==========尚未定义============
	if (!found) {
		return -1;														//未找到该记录
	}
	if (duration <= 0) {
		return -2;														//延长时间应为正整数 
	}
	//更新时长
	if (record.getStatus() == Record::EXCEED) { record.setStatus(Record::NORMAL); }
	record.setDuration(record.getDuration() + duration);					//设置新借阅时长

	if (recordDao.updateRecord(recordId, record)) {
		return 0;														//还书成功
	}
	return -3;															//其他出错情况														
}
int  RecordService::returnBook(int recordId)						
{
	/*Mission:	 Abook状态变为NORMAL 记录状态变为RETURNED*/
	//检测用户是否存在
	bool found;
	Record record = recordDao.findRecordById(recordId, found);		  //《=============尚未定义
	
	ABook abook = aBookDao.findABookById(record.getABookId(), found);									
	abook.setStatus(ABook::NORMAL);
	
	Book book = bookDao.findBookById(record.getBookId(),found);
	book.setQuantity(book.getQuantity() + 1);
	record.setStatus(Record::RETURNED);

}
vector<Record> RecordService::findAllRecord()
{
	return recordDao.findAllRecord();
}
vector<Record> RecordService::findRecordByBookId(int bookId)
{
	return recordDao.findRecordByBookId(bookId);
}
vector<Record> RecordService::findRecordByUserId(int userId)
{
	return recordDao.findRecordByUserId(userId);
}