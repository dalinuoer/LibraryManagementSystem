#pragma once
#include <string>
#include "ABook.h"
#include "Dao.hpp"

using namespace std;

class ABookDao
{
public:
	ABookDao(const string &filename);
	~ABookDao();
	int insertABook(const ABook &aBook);
	bool updateABook(int id, const ABook &aBook);
	bool deleteABook(int id);
	ABook findABookById(int id, bool &found);
	vector<ABook> findABookByBookId(int bookId);
	vector<ABook> findAllABook();

private:
	Dao<ABook> dao;
	string filename;
	fstream file;
};

