#include "RecordService.h"
#include <ctime>
#include <sstream>

string getDate()
{
	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
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
	//����û��Ƿ����
	bool foundU;
	User user = userDao.findUserById(userId, foundU);
	if (!foundU)
	{
		return false;													//δ�ҵ����û� -1
	}

	//������Ƿ���ڣ���Ӧ�ô��ڣ���Ϊ�ϲ㴫��������bookId �Ǿ�������;����ѯ��֪��
	bool foundB;
	ABook abook = aBookDao.findABookById(aBookId, foundB);
	if (!foundB)
	{
		return false;													//δ�ҵ���		-2
	}

	//�������Ƿ�ɾ��													//���ѱ�ɾ��    -3
	if (abook.getStatus() == ABook::DELETED)
	{
		return false;
	}


	//�������Ƿ���ʣ��	
	Book book = bookDao.findBookById(abook.getBookId(), foundB);
	if (book.getQuantity() == 0)
	{
		return false;											//����ʣ��		-4
	}
	//��ʣ��������н��Ĳ���
	Record record;
	record.setBookId(aBookId);
	record.setUserId(userId);
	record.setStatus(Record::NORMAL);
	record.setId(0);
	record.setDate(getDate());												//��========================���ø���ʱ��=======================================
	record.setDuration(15);
	record.setReturnDate("δ�黹");
	book.setQuantity(book.getQuantity() - 1);
	abook.setStatus(ABook::BORROWED);
	if (recordDao.insertRecord(record) != -1)
	{
		return true;												//����ɹ�		0
	}

	return false;														//�������������������ʧ�� -5
}

bool RecordService::renewBook(int recordId, int duration)
{
	//�����ü�¼
	bool found;
	Record record = recordDao.findRecordById(recordId, found);
	if (!found)
	{
		return false;														//δ�ҵ��ü�¼
	}
	if (duration <= 0)
	{
		return false;														//�ӳ�ʱ��ӦΪ������ 
	}
	//����ʱ��
	if (record.getStatus() == Record::EXCEED)
	{
		record.setStatus(Record::NORMAL);
	}
	record.setDuration(record.getDuration() + duration);					//�����½���ʱ��

	if (recordDao.updateRecord(recordId, record))
	{
		return true;														//����ɹ�
	}
	return false;															//�����������														
}

bool  RecordService::returnBook(int recordId)
{
	/*Mission:	 Abook״̬��ΪNORMAL ��¼״̬��ΪRETURNED*/
	//����û��Ƿ����
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
	//RecordVo record�ֶ�
	vo.setId(record.getId());
	vo.setABookId(record.getBookId());
	vo.setBookId(record.getABookId());
	vo.setDate(record.getDate());
	vo.setDuration(record.getDuration());
	vo.setReturnDate(record.getReturnDate());
	vo.setStatus(record.getStatus());
	//RecordVo user�ֶ�
	vo.setUserName(user.getName());
	//RecordVo book�ֶ�
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
		//RecordVo record�ֶ�
		vo.setId(record.getId());
		vo.setABookId(record.getBookId());
		vo.setBookId(record.getABookId());
		vo.setDate(record.getDate());
		vo.setDuration(record.getDuration());
		vo.setReturnDate(record.getReturnDate());
		vo.setStatus(record.getStatus());
		//RecordVo user�ֶ�
		vo.setUserName(user.getName());
		//RecordVo book�ֶ�
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
		//RecordVo record�ֶ�
		vo.setId(record.getId());
		vo.setABookId(record.getBookId());
		vo.setBookId(record.getABookId());
		vo.setDate(record.getDate());
		vo.setDuration(record.getDuration());
		vo.setReturnDate(record.getReturnDate());
		vo.setStatus(record.getStatus());
		//RecordVo user�ֶ�
		vo.setUserName(user.getName());
		//RecordVo book�ֶ�
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
		//RecordVo record�ֶ�
		vo.setId(record.getId());
		vo.setABookId(record.getBookId());
		vo.setBookId(record.getABookId());
		vo.setDate(record.getDate());
		vo.setDuration(record.getDuration());
		vo.setReturnDate(record.getReturnDate());
		vo.setStatus(record.getStatus());
		//RecordVo user�ֶ�
		vo.setUserName(user.getName());
		//RecordVo book�ֶ�
		vo.setAuthor(book.getAuthor());
		vo.setPublisher(book.getPublisher());

		voList.push_back(vo);
	}
	return voList;
}