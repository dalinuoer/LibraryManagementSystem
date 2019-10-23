#include "TypeService.h"


TypeService::TypeService() : typeDao("data/Type.dat")
{
}


TypeService::~TypeService()
{
}

BookType TypeService::findTypeById(int id, bool &found)
{
	return typeDao.findTypeById(id, found);
}

vector<BookType> TypeService::findAllType()
{
	return typeDao.findAllType();
}
