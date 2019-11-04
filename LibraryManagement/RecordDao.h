#pragma once
#include "Record.h"
#include <vector>
#include <string>
#include <fstream>
#include "Dao.hpp"

using namespace std;

class RecordDao
{
public:
	RecordDao(const string &filename);
	~RecordDao();
	int insertRecord(const Record &record);
	bool deleteRecord(int id);
	bool updateRecord(int id, const Record &record);
	Record findRecordById(int id, bool &found);
	vector<Record> findAllRecord();
	vector<Record> findRecordByUserId(const string &userId);
	vector<Record> findRecordByBookId(int bookId);
	Record findRecordByUserIdAndBookId(const string &userId, int bookId, bool &found);

private:
	Dao<Record> dao;
	string filename;
	fstream file;
};
