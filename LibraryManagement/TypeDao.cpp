#include "TypeDao.h"

TypeDao::TypeDao() : dao("data/Type.dat")
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

vector<BookType> TypeDao::findAllType()
{
	return dao.findAll();
}