#include "RecordDao.h"
#include <iostream>

using namespace std;

RecordDao::RecordDao(string filename) : dao(filename)
{
	this->filename = filename;
}

RecordDao::~RecordDao()
{
}

bool RecordDao::insertRecord(const Record &record)
{
	return dao.insert(record);
}

bool RecordDao::deleteRecord(int id)
{
	return dao.del(id);
}

bool RecordDao::updateRecord(int id, const Record &record)
{
	return dao.update(id, record);
}

vector<Record> RecordDao::findAllRecord()
{
	return dao.findAll();
}

Record RecordDao::findRecordById(int id, bool &found)
{
	return dao.findById(id, found);
}

vector<Record> RecordDao::findRecordByBookId(int bookId)
{
	vector<Record> dataList;
	file.open(filename, ios::binary | ios::in);
	while (!file.eof())
	{
		Record record;
		file.read((char*)&record, sizeof(Record));
		if (file.gcount() != 0)
		{
			if (record.getBookId() == bookId)
			{
				dataList.push_back(record);
			}
		}
	}
	file.close();
	return dataList;
}

vector<Record> RecordDao::findRecordByUserId(int userId)
{
	vector<Record> dataList;
	file.open(filename, ios::binary | ios::in);
	while (!file.eof())
	{
		Record record;
		file.read((char *)&record, sizeof(Record));
		if (file.gcount() != 0)
		{
			if (record.getUserId() == userId)
			{
				dataList.push_back(record);
			}
		}
	}
	file.close();
	return dataList;
}

Record RecordDao::findRecordByUserIdAndBookId(int userId, int bookId, bool &found)
{
	Record data;
	file.open(filename, ios::binary | ios::in);
	file.seekg(ios::beg);
	found = false;
	while (!file.eof())
	{
		file.read((char*)&data, sizeof(Record));
		if (data.getBookId() == bookId && data.getUserId() == userId)
		{
			found = true;
			break;
		}
	}
	file.close();
	return data;
}
