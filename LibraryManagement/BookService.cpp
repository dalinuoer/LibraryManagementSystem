#include "BookService.h"


BookService::BookService() :bookDao("data/Book.dat"), aBookDao("data/ABook.dat")
{
}

int BookService::addBook(Book book)
{
	int id = bookDao.insertBook(book);
	for (int i = 0; i < book.getQuantity(); i++)
	{
		ABook aBook;
		aBook.setBookId(id);
		aBook.setStatus(ABook::NORMAL);
		aBookDao.insertABook(aBook);
	}
	return SUCCESS;
}

int BookService::changeBookInfo(int id, const Book& book)
{
	bool found;
	Book b = bookDao.findBookById(id, found);
	if (found && !b.getStatus())
	{
		if (bookDao.updateBook(id, book))
		{
			return SUCCESS;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return BOOK_NOT_FOUND;
	}
}

int BookService::delBook(int id)
{
	bool found;
	Book book = bookDao.findBookById(id, found);
	if (found)
	{
		
		if (book.getStatus() == Book::NORMAL)
		{
			bookDao.deleteBook(id);
			return SUCCESS;
		}
		else if (book.getStatus() == Book::DELETED)
		{
			return ERROR;
		}
	}
	else
	{
		return BOOK_NOT_FOUND;
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
