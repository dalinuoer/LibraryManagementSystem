#pragma once
#include "TypeDao.h"
#include <vector>

using namespace std;

class TypeService
{
public:
	TypeService();
	~TypeService();
	vector<BookType> findAllType();

private:
	TypeDao typeDao;
};

