#include "TypeDao.h"

TypeDao::TypeDao(const string &filename) : dao(filename)
{
}


TypeDao::~TypeDao()
{
}

bool TypeDao::insertType(const BookType &type)
{
	return dao.insert(type);
}


bool TypeDao::updateType(int id, const BookType &type)
{
	return dao.update(id, type);
}

bool TypeDao::deleteType(int id)
{
	return dao.del(id);
}

BookType TypeDao::findTypeById(int id, bool &found)
{
	return dao.findById(id, found);
}

vector<BookType> TypeDao::findAllType()
{
	return dao.findAll();
}