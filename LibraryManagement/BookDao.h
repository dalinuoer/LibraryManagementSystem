#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Book.h"
#include "ABook.h"
#include "BookType.h"
#include "Dao.hpp"

using namespace std;

class BookDao
{
public:
	BookDao(const string &filename);
	~BookDao();
	int insertBook(const Book &book);
	bool updateBook(int id, const Book &book);
	bool deleteBook(int id);
	Book findBookById(int id, bool &found);
	vector<Book> findBookByName(const string &name);
	vector<Book> findAllBook();

private:
	Dao<Book> dao;
	string filename;
	fstream file;
};

