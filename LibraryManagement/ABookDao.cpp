#include "ABookDao.h"

ABookDao::ABookDao(string filename) : dao(filename)
{
}


ABookDao::~ABookDao()
{
}


bool ABookDao::insertABook(const ABook &aBook)
{
	return dao.insert(aBook);
}

bool ABookDao::updateABook(int id, const ABook &aBook)
{
	return dao.update(id, aBook);
}

bool ABookDao::deleteABook(int id)
{
	return dao.del(id);
}

ABook ABookDao::findABookById(int id, bool &found)
{
	return dao.findById(id, found);
}