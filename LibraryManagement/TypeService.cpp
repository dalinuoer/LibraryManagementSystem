#include "TypeService.h"


TypeService::TypeService() : typeDao("data/Type.dat")
{
}


TypeService::~TypeService()
{
}

bool TypeService::insertType(const BookType& type)
{
	return typeDao.insertType(type);
}

bool TypeService::updateType(int id, const BookType& type)
{
	return typeDao.updateType(id, type);
}

BookType TypeService::findTypeById(int id, bool &found)
{
	return typeDao.findTypeById(id, found);
}

vector<BookType> TypeService::findAllType()
{
	return typeDao.findAllType();
}
