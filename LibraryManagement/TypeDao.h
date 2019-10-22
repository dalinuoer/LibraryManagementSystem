#pragma once
#include "Dao.hpp"
#include "BookType.h"
#include <vector>

using namespace std;

class TypeDao
{
public:
	TypeDao();
	~TypeDao();
	bool insertType(const BookType &type);
	bool updateType(int id, const BookType &type);
	bool deleteType(int id);
	vector<BookType> findAllType();
private:
	Dao<BookType> dao;
};

