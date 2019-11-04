#pragma once
#include "Book.h"
#include "BookDao.h"
#include "ABookDao.h"
#include <vector>
#include <string>
#include "ABookVo.h"

class BookService 
{

public:
	const static int SUCCESS = 0;
	const static int BOOK_NOT_FOUND = 1;
	const static int ERROR = 2;

public:
	BookService();
	int addBook(Book book);
	int changeBookInfo(int id, const Book& book);
	int delBook(int id);
	vector<Book> findAllBook();
	vector<Book> findBookByName(string name);
	Book findBookById(int id, bool &found);
	vector<ABookVo> findABookByBookId(int bookId);
	

private:
	BookDao bookDao;
	ABookDao aBookDao;
};