#pragma once
#include"Book.h"
#include"BookDao.h"
#include<vector>
#include<string>
class BookService {
public:
	BookService();
	bool addBook(Book book);
	bool changeBookInfo(int id, const Book& book);
	bool delBook(int id);
	vector<Book> findAllBook();
	vector<Book> findBookByName(string name);
	Book findBookById(int id, bool &found);

private:
	BookDao bookDao;
};