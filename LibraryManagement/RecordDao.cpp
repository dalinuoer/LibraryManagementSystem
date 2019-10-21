#include "RecordDao.h"
#include<iostream>

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