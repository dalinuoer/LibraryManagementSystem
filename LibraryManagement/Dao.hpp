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
		file.seekp(ios::end);
		file.write((char*)&data, sizeof(data));
		return true;
	}

	int findById(int id)
	{
		T data;
		file.seekg(ios::beg);
		while (!file.eof())
		{
			file.read((char*)&data, sizeof(T));
			if (data.getId() == id)
			{
				break;
			}
		}
		return file.tellg() - sizeof(T);
	}

	bool update(int id, T data)
	{
		int pos = findById(id);
		file.write((char*)&data, sizeof(T));
		return true;
	}

private:
	fstream file;
};