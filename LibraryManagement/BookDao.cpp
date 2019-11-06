#include "BookDao.h"

BookDao::BookDao(const string &filename) : dao(filename), filename(filename)
{
}


BookDao::~BookDao()
{
}

int BookDao::insertBook(const Book &book)
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

vector<Book> BookDao::findBookByName(const string &name)
{
	vector<Book> bookList;
	file.open(filename, ios::binary | ios::in);
	file.seekg(sizeof(int), ios::beg);
	while (!file.eof())
	{
		Book data;
		file.read((char*)&data, sizeof(Book));
		if (file.gcount() != 0)
		{
			if (data.getName().find(name) != string::npos)
			{
				bookList.push_back(data);
			}
		}
	}
	file.close();
	return bookList;
}

Book BookDao::findBookByISBN(const string &ISBN,bool &found)
{
	Book data;
	file.open(filename, ios::binary | ios::in);
	file.seekg(sizeof(int), ios::beg);
	found = false;
	while (!file.eof())
	{
		file.read((char*)&data, sizeof(Book));
		if (data.getISBN() == ISBN )
		{
			found = true;
			break;
		}
	}
	file.close();
	return data;
}

vector<Book> BookDao::findAllBook()
{
	return dao.findAll();
}