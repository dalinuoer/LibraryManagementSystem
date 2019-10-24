#pragma once
#include <fstream>
#include <string>

using namespace std;

template <class T>
class DataBase
{
public:
	DataBase(const string &filename) : filename(filename)
	{
		file.open(filename, ios::in);
		if (!file)
		{
			file.close();
			file.open(filename, ios::out);
			file.close();
		}
		file.close();
	}


private:
	string filename;
	fstream file;
};