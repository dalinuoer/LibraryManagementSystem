#include "BookDao.h"


BookDao::BookDao(string filename) : dao(filename),dao1(filename)
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
	return data;
}

vector<Book> BookDao::findAllBook()
{
	return dao.findAll();
}

bool BookDao::insertABook(const ABook &aBook)
{
	return dao1.insert(aBook);
}

bool BookDao::updateABook(int id, const ABook &aBook)
{
	return dao1.update(id, aBook);
}

bool BookDao::deleteABook(int id)
{
	return dao1.del(id);
}

ABook BookDao::findABookById(int id, bool &found)
{
	return dao1.findById(id, found);
}