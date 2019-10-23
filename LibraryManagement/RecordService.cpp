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
	//����û��Ƿ����
	bool foundU;
	User user = userDao.findUserById(userId, foundU);
	if (!foundU)
	{
		return -1;													//δ�ҵ����û� -1
	}

	//������Ƿ���ڣ���Ӧ�ô��ڣ���Ϊ�ϲ㴫��������bookId �Ǿ�������;����ѯ��֪��
	bool foundB;
	ABook abook = aBookDao.findABookById(AbookId, foundB);
	if (!foundB)
	{
		return -2;													//δ�ҵ���		-2
	}

	//�������Ƿ�ɾ��													//���ѱ�ɾ��    -3
	if (abook.getStatus() == ABook::DELETED) 
	{
		return -3;
	}


	//�������Ƿ���ʣ��	
	Book book = bookDao.findBookById(abook.getBookId(), foundB);
	if (book.getQuantity() == 0) 
	{
		return -4;													//����ʣ��		-4
	}
	//��ʣ��������н��Ĳ���
	Record record;
	record.setBookId(AbookId);
	record.setUserId(userId);
	record.setStatus(Record::NORMAL);
	record.setId(0);
	record.setDate("");												//��========================���ø���ʱ��=======================================
	record.setDuration(1);
	record.setReturnDate("δ�黹");
	book.setQuantity(book.getQuantity() - 1);
	abook.setStatus(ABook::BORROWED);
	if (recordDao.insertRecord(record)) 
	{
		return 0;													//����ɹ�		0
	}

	return -5;														//�������������������ʧ�� -5

}

int RecordService::renewBook(int recordId, int duration)
{
	//�����ü�¼
	bool found;
	Record record = recordDao.findRecordById(recordId, found);
	if (!found) 
	{
		return -1;														//δ�ҵ��ü�¼
	}
	if (duration <= 0) 
	{
		return -2;														//�ӳ�ʱ��ӦΪ������ 
	}
	//����ʱ��
	if (record.getStatus() == Record::EXCEED)
	{
		record.setStatus(Record::NORMAL);
	}
	record.setDuration(record.getDuration() + duration);					//�����½���ʱ��

	if (recordDao.updateRecord(recordId, record)) 
	{
		return 0;														//����ɹ�
	}
	return -3;															//�����������														
}

bool  RecordService::returnBook(int recordId)
{
	/*Mission:	 Abook״̬��ΪNORMAL ��¼״̬��ΪRETURNED*/
	//����û��Ƿ����
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
	Record record = findRecordByUserIdAndBookId(userid, bookid, found);

	ABook abook = aBookDao.findABookById(record.getABookId(), found);
	abook.setStatus(ABook::NORMAL);

	Book book = bookDao.findBookById(bookid, found);
	book.setQuantity(book.getQuantity() + 1);

	record.setStatus(Record::RETURNED);
	return true;
}

Record RecordService::findRecordByUserIdAndBookId(int userid, int bookid, bool &found)
{
	return recordDao.findRecordByUserIdAndBookId(userid, bookid, found);
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