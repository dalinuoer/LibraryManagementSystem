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
	Dao(string filename)
	{
		this->filename = filename;
	}

	~Dao() 
	{
	}

	bool insert(const T &data)
	{
		file.open(filename, ios::app);
		file.write((char*)&data, sizeof(T));
		file.close();
		return true;
	}

	bool del(int id)
	{
		return true;
	}

	bool update(int id, T data)
	{
		int pos = findPosition(id);
		cout << pos << endl;
		if (pos != -1)
		{
			file.open(filename, ios::binary | ios::out | ios::in);
			if (!file)
			{
				cout << "文件打开失败" << endl;
				exit(0);
			}
			file.seekp(pos, ios::beg);
			file.write((char*)&data, sizeof(T));
			file.close();
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
		file.open(filename, ios::binary | ios::in);
		file.seekg(ios::beg);
		bool found = false;
		while (!file.eof())
		{
			file.read((char*)&data, sizeof(T));
			if (data.getId() == id)
			{
				found = true;
				break;
			}
		}
		int pos = 0;
		if (found)
		{
			pos = file.tellg() - (long long)sizeof(T);
		}
		else
		{
			pos = -1;
		}
		file.close();
		return pos;
	}

	T findById(int id, bool &found)
	{
		T data;
		int pos = findPosition(id);
		if (pos != -1)
		{
			found = true;
			file.open(filename, ios::binary | ios::in);
			file.seekg(pos, ios::beg);
			file.read((char*)&data, sizeof(T));
			file.close();
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
		file.open(filename, ios::binary | ios::in);
		while (!file.eof())
		{
			T data;
			file.read((char*)&data, sizeof(T));
			if (file.gcount() != 0)
			{
				dataList.push_back(data);
			}
		}
		file.close();
		return dataList();
	}

private:
	string filename;
	fstream file;
};