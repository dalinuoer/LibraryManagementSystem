#include "ABookDao.h"

ABookDao::ABookDao(const string &filename) : dao(filename)
{
	this->filename = filename;
}


ABookDao::~ABookDao()
{
}


int ABookDao::insertABook(const ABook &aBook)
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

vector<ABook> ABookDao::findABookByBookId(int bookId)
{
	vector<ABook> dataList;
	file.open(filename, ios::binary | ios::in);
	file.seekg(sizeof(int), ios::beg);
	while (!file.eof())
	{
		ABook data;
		file.read((char*)&data, sizeof(ABook));
		if (file.gcount() != 0)
		{
			if (data.getBookId() == bookId)
			{
				dataList.push_back(data);
			}
		}
	}
	file.close();
	return dataList;
}

vector<ABook> ABookDao::findAllABook()
{
	return dao.findAll();
}