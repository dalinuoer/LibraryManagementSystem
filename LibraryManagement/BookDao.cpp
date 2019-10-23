#include "BookDao.h"

BookDao::BookDao(const string &filename) : dao(filename), filename(filename)
{
}


BookDao::~BookDao()
{
}

bool BookDao::insertBook(const Book &book)
{
	return dao.insert(book);
}

bool BookDao::updateBook(int id, const Book &book)
{
	return dao.update(id, book);
}

bool BookDao::deleteBook(int id)
{
	return dao.del(id);
}

Book BookDao::findBookById(int id, bool &found)
{
	return dao.findById(id, found);
}

vector<Book> BookDao::findBookByName(const string &name, bool &found)
{
	vector<Book> bookList;
	file.open(filename, ios::binary | ios::in);
	file.seekg(ios::beg);
	found = false;
	while (!file.eof())
	{
		Book data;
		file.read((char*)&data, sizeof(Book));
		if (file.gcount() != 0)
		{
			if (data.getName() == name)
			{
				found = true;
			}
		}
	}
	file.close();
	return bookList;
}

vector<Book> BookDao::findAllBook()
{
	return dao.findAll();
}