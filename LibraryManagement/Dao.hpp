#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>
class Dao
{
public:
	Dao(string filename) 
	{
		file.open(filename, ios::out | ios::in);
		if (!file)
		{
			cout << "打开文件失败！" << endl;
			return;
		}
	}

	~Dao() 
	{
		file.flush();
		file.close();
	}

	bool insert(T data)
	{
		file.seek
		file.write((char*)&data, sizeof(data));
	}


private:
	fstream file;
};