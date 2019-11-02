#pragma once
#include "Book.h"
#include "BookDao.h"
#include "ABookDao.h"
#include <vector>
#include <string>
#include "ABookVo.h"

class BookService {
public:
	BookService();
	bool addBook(Book book);
	bool changeBookInfo(int id, const Book& book);
	bool delBook(int id);
	vector<Book> findAllBook();
	vector<Book> findBookByName(string name);
	Book findBookById(int id, bool &found);
	vector<ABookVo> findABookByBookId(int bookId);

private:
	BookDao bookDao;
	ABookDao aBookDao;
};