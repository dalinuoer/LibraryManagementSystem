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
		file.open(filename, ios::in);
		if (!file)
		{
			file.close();
			file.open(filename, ios::out);
			file.close();
		}
		file.close();
	}

	~Dao() 
	{
	}

	int insert(const T &data)
	{
		//获取当前最新id
		file.open(filename, ios::binary | ios::in);
		int id = 0;
		file.read((char*)&id, sizeof(int));
		if (file.gcount() == 0)
		{
			id = 0;
		}
		else
		{
			id = id + 1;  //将id加一作为新加入项目的id
		}
		file.close();
		//将新id写入文件头
		file.open(filename, ios::binary | ios::out | ios::in);
		file.seekp(ios::beg);
		file.write((char*)&id, sizeof(int));
		file.close();
		//插入新项目
		file.open(filename, ios::binary | ios::out | ios::app);
		if (!file)
		{
			cout << "打开文件失败" << endl;
		}
		file.write((char*)&id, sizeof(int));
		file.write((char*)&data + sizeof(int), sizeof(T) - sizeof(int));
		file.close();
		return id;
	}

	bool del(int id)
	{
		bool found;
		T data = findById(id, found);
		if (found)
		{
			data.setDelete();
			return update(id, data);
		}
		else
		{
			return false;
		}
	}

	bool update(int id,const T &data)
	{
		int pos = getPosition(id);
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

	int getPosition(int id)
	{
		T data;
		file.open(filename, ios::binary | ios::in);
		file.seekg(sizeof(int), ios::beg);
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
		int pos = getPosition(id);
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
		file.seekg(sizeof(int), ios::beg);
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
		return dataList;
	}

private:
	string filename;
	fstream file;
};