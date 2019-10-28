#include "BookService.h"


BookService::BookService():bookDao("data/Book.dat")
{
}

bool BookService::addBook(Book book)
{
	return bookDao.insertBook(book);
}

bool BookService::changeBookInfo(int id, const Book& book)
{
	bool found;
	bookDao.findBookById(id, found);
	if (found)
	{
		return bookDao.updateBook(id, book);
	}
	else
	{
		return false;
	}
}

bool BookService::delBook(int id)
{
	bool found;
	bookDao.findBookById(id, found);
	if (found) 
	{
		return bookDao.deleteBook(id);
	}
	else
	{
		return false;
	}
}

vector<Book> BookService::findAllBook()
{
	return bookDao.findAllBook();
}

Book BookService::findBookById(int id, bool & found)
{
	return bookDao.findBookById(id, found);
}

vector<Book> BookService::findBookByName(string name)
{
	return bookDao.findBookByName(name);
}
