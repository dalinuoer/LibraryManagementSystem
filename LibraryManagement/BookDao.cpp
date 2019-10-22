#include "BookDao.h"

BookDao::BookDao(string filename) : dao(filename)
{
	this->filename = filename;
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

Book BookDao::findBookByName(const string &name, bool &found)
{
	Book data;
	file.open(filename,ios::binary | ios::in);
	file.seekg(ios::beg);
	found = false;
	while (!file.eof())
	{
		file.read((char*)&data,sizeof(Book));
		if (data.getName() == name)
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