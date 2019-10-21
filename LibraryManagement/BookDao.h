#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "book.h"
#include "ABook.h"
#include "Dao.hpp"

using namespace std;

class BookDao
{
public:
	BookDao(string filename);
	~BookDao();
	bool insertBook(const Book &book);
	bool updateBook(int id, const Book &book);
	bool deleteBook(int id);
	Book findBookById(int id, bool &found);
	Book findBookByName(const string &name, bool &found);
	vector<Book> findAllBook();

	bool insertABook(const ABook &aBook);
	bool updateABook(int id, const ABook &aBook);
	bool deleteABook(int id);
	ABook findABookById(int id, bool &found);

private:
	Dao<Book> dao;
	Dao<ABook> dao1;
	string filename;
	fstream file;
};

