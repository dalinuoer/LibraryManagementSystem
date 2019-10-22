#pragma once
#include "Dao.hpp"
#include "BookType.h"
#include <vector>

using namespace std;

class TypeDao
{
public:
	TypeDao(string filename);
	~TypeDao();
	bool insertType(const BookType &type);
	bool updateType(int id, const BookType &type);
	bool deleteType(int id);
	BookType findTypeById(int id, bool &found);
	vector<BookType> findAllType();
private:
	Dao<BookType> dao;
};

