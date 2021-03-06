#pragma once
#include "TypeDao.h"
#include <vector>

using namespace std;

class TypeService
{
public:
	TypeService();
	~TypeService();
	bool insertType(const BookType& type);
	bool updateType(int id, const BookType& type);
	BookType findTypeById(int id, bool &found);
	vector<BookType> findAllType();

private:
	TypeDao typeDao;
};

