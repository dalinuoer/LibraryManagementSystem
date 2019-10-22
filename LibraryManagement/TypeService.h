#pragma once
#include "TypeDao.h"
#include <vector>

using namespace std;

class TypeService
{
public:
	TypeService();
	~TypeService();
	BookType findTypeById(int id, bool &found);
	vector<BookType> findAllType();

private:
	TypeDao typeDao;
};

