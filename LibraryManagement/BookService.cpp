#include "BookService.h"


BookService::BookService():bookDao("data/Book.dat"), aBookDao("data/ABook.dat")
{
}

bool BookService::addBook(Book book)
{
	bool result = false;
	result = bookDao.insertBook(book);
	for (int i = 0; i < book.getQuantity(); i++)
	{
		ABook aBook;
		aBook.setBookId(book.getId());
		aBook.setStatus(ABook::NORMAL);
		result &= aBookDao.insertABook(aBook);
	}
	return result;
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

vector<ABookVo> BookService::findABookByBookId(int bookId)
{
	vector<ABookVo> list;
	vector<ABook> aBooks = aBookDao.findABookByBookId(bookId);
	for (ABook aBook : aBooks)
	{
		int bookId = aBook.getBookId();
		bool found = false;
		Book book = bookDao.findBookById(bookId, found);
		if (found)
		{
			ABookVo aBookVo(book, aBook);
			list.push_back(aBookVo);
		}
	}
	return list;
}
