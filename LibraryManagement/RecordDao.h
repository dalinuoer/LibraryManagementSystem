#pragma once
#include"Record.h"
#include <vector>
#include <string>
#include <fstream>
#include "Dao.hpp"

using namespace std;

class RecordDao
{
public:
	RecordDao(string filename);
	~RecordDao();
	bool insertRecord(const Record &record);
	bool deleteRecord(int id);
	bool updateRecord(int id, const Record &record);

private:
	Dao<Record> dao;
	string filename;
	fstream file;
};

