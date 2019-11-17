#include "RecordService.h"
#include <ctime>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>


bool compareBookR(pair<int, set<string>> a, pair<int, set<string>> b) {
	return a.second.size() > b.second.size();
}

bool compareUserR(pair<string, set<int>> a, pair<string, set<int>> b) {
	return a.second.size() > b.second.size();
}

vector<Book> RecordService::bookRank()
{
	vector<RecordVo> recordVos = findAllRecord();
	map<int, set<string>> bookR;
	for (auto record : recordVos)
	{
		int bookId = record.getBookId();
		if (bookR.find(bookId) == bookR.end())
		{
			bookR.insert(pair<int, set<string>>(bookId, set<string>()));
		}
		else
		{
			bookR[bookId].insert(record.getUserId());
		}
	}
	vector<pair<int, set<string>>> vec(bookR.begin(), bookR.end());
	sort(vec.begin(), vec.end(), compareBookR);

	vector<Book> books;
	for (int i = 0; i < 10 && i < vec.size(); ++i)
	{
		bool found = false;
		int id = vec[i].first;
		Book book = bookDao.findBookById(id, found);
		books.push_back(book);
	}
	return books;
}

vector<User> RecordService::userRank()
{
	vector<RecordVo> recordVos = findAllRecord();
	map<string, set<int>> userR;
	for (auto record : recordVos)
	{
		string userId = record.getUserId();
		if (userR.find(userId) == userR.end())
		{
			userR.insert(pair<string, set<int>>(userId, set<int>()));
		}
		else
		{
			userR[userId].insert(record.getBookId());
		}
	}
	vector<pair<string, set<int>>> vec(userR.begin(), userR.end());
	sort(vec.begin(), vec.end(), compareUserR);

	vector<User> users;
	for (int i = 0; i < 10 && i < vec.size(); ++i)
	{
		bool found = false;
		string id = vec[i].first;
		User user = userDao.findUserById(id, found);
		users.push_back(user);
	}
	return users;
}

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

int RecordService::borrowBook(const string &userId, int aBookId)
{
	//����û��Ƿ����
	bool foundU;
	User user = userDao.findUserById(userId, foundU);
	if (!foundU || user.getStatus() != User::NORMAL)
	{
		return USER_NOT_FOUND;													//δ�ҵ����û� USER_NOT_FOUND
	}

	//������Ƿ���ڣ���Ӧ�ô��ڣ���Ϊ�ϲ㴫��������bookId �Ǿ�������;����ѯ��֪��
	bool foundB;
	ABook abook = aBookDao.findABookById(aBookId, foundB);
	if (!foundB || abook.getStatus() != ABook::NORMAL)
	{
		return ABOOK_NOT_FOUND;											//δ�ҵ��Ȿ�� ABOOK_NOT_FOUND
	}
	abook.setStatus(ABook::BORROWED);
	aBookDao.updateABook(abook.getId(), abook);

	Book book = bookDao.findBookById(abook.getBookId(), foundB);

	//��ʣ��������н��Ĳ���
	Record record;
	record.setBookId(aBookId);
	record.setABookId(aBookId);
	record.setUserId(userId);
	record.setStatus(Record::NORMAL);
	record.setId(0);
	record.setDate(getDate());												//��========================���ø���ʱ��=======================================
	record.setDuration(1);
	record.setReturnDate("δ�黹");
	if (recordDao.insertRecord(record) != -1)
	{
		return SUCCESS;												//����ɹ�		0
	}

	return ERROR;														//�������������������ʧ�� -5
}

int RecordService::renewBook(int recordId, int duration)
{
	//�����ü�¼
	bool found;
	Record record = recordDao.findRecordById(recordId, found);
	if (!found)
	{
		return RECORD_NOT_FOUND;											//δ�ҵ��ü�¼
	}
	

	//����ʱ��
	if (record.getStatus() == Record::EXCEED)
	{
		record.setStatus(Record::NORMAL);
	}
	record.setDuration(record.getDuration() + duration);					//�����½���ʱ��

	if (recordDao.updateRecord(recordId, record))
	{
		return SUCCESS;														//����ɹ�
	}
	return ERROR;															//�����������														
}

int  RecordService::returnBook(int recordId)
{
	/*Mission:	 Abook״̬��ΪNORMAL ��¼״̬��ΪRETURNED*/
	//����û��Ƿ����
	bool found;
	Record record = recordDao.findRecordById(recordId, found);
	if (!found)
	{
		return RECORD_NOT_FOUND;
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

	return SUCCESS;
}

int RecordService::returnBook(const string &userId, int bookid)
{
	bool found;
	Record record = recordDao.findRecordByUserIdAndBookId(userId, bookid, found);
	if (!found)
	{
		return RECORD_NOT_FOUND;
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

	
	return SUCCESS;
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