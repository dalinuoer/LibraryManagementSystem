#include "BookService.h"



BookService::BookService():bookDao("Book.dat")
{
}

bool BookService::addBook(Book book)
{
	return bookDao.insertBook(book);
}

bool BookService::delBook(int id)
{
	return bookDao.deleteBook(id);
}

vector<Book> BookService::findAllBook()
{
	return bookDao.findAllBook();
}

Book BookService::findBookById(int id, bool & found)
{
	return bookDao.findBookById(id, found);
}


vector<Book> BookService::findBookByName(string name,bool &found)
{
	return bookDao.findBookByName(name,found);
}
