#include "TypeService.h"


TypeService::TypeService()
{
}


TypeService::~TypeService()
{
}

vector<BookType> TypeService::findAllType()
{
	return typeDao.findAllType();
}
