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
			cout << "���ļ�ʧ�ܣ�" << endl;
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