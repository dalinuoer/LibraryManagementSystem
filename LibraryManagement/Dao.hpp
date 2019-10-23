#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class Dao
{
public:
	Dao(const string &filename) : filename(filename)
	{
		dataFile.open(filename, ios::in);
		if (!dataFile)
		{
			dataFile.close();
			dataFile.open(filename, ios::out);
			dataFile.close();
		}
		dataFile.close();
	}

	~Dao() 
	{
	}

	bool insert(const T &data)
	{
		dataFile.open(filename, ios::binary | ios::out | ios::app);
		if (!dataFile)
		{
			cout << "打开文件失败" << endl;
		}
		dataFile.write((char*)&data, sizeof(T));
		dataFile.close();
		return true;
	}

	bool del(int id)
	{
		return true;
	}

	bool update(int id,const T &data)
	{
		int pos = findPosition(id);
		if (pos != -1)
		{
			dataFile.open(filename, ios::binary | ios::out | ios::in);
			if (!dataFile)
			{
				cout << "文件打开失败" << endl;
				exit(0);
			}
			dataFile.seekp(pos, ios::beg);
			dataFile.write((char*)&data, sizeof(T));
			dataFile.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	int findPosition(int id)
	{
		T data;
		dataFile.open(filename, ios::binary | ios::in);
		dataFile.seekg(ios::beg);
		bool found = false;
		while (!dataFile.eof())
		{
			dataFile.read((char*)&data, sizeof(T));
			if (data.getId() == id)
			{
				found = true;
				break;
			}
		}
		int pos = 0;
		if (found)
		{
			pos = dataFile.tellg() - (long long)sizeof(T);
		}
		else
		{
			pos = -1;
		}
		dataFile.close();
		return pos;
	}

	T findById(int id, bool &found)
	{
		T data;
		int pos = findPosition(id);
		if (pos != -1)
		{
			found = true;
			dataFile.open(filename, ios::binary | ios::in);
			dataFile.seekg(pos, ios::beg);
			dataFile.read((char*)&data, sizeof(T));
			dataFile.close();
		}
		else
		{
			found = false;
		}
		return data;
	}

	vector<T> findAll()
	{
		vector<T> dataList;
		dataFile.open(filename, ios::binary | ios::in);
		dataFile.seekg(ios::beg);
		while (!dataFile.eof())
		{
			T data;
			dataFile.read((char*)&data, sizeof(T));
			if (dataFile.gcount() != 0)
			{
				dataList.push_back(data);
			}
		}
		dataFile.close();
		return dataList;
	}

private:
	string filename_data;
	string filename_DB;
	fstream dataFile;
	fstream DBFile;
};