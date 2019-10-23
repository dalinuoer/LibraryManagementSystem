#include <iostream>
#include <fstream>
#include "User.h"
#include "Book.h"
#include "ABook.h"
#include "BookType.h"
#include "Record.h"
#include "UserDao.h"
#include "BookDao.h"
#include "consoleCommand.h"

using namespace std;

int main()
{
	TypeDao typeDao("data/Type.dat");

	BookType type;
	type.setId(0);
	type.setName("�������");
	typeDao.insertType(type); 

	type.setId(1);
	type.setName("��ѧ��");
	typeDao.insertType(type);

	type.setId(2);
	type.setName("��Ȼ��ѧ��");
	typeDao.insertType(type);

	return 0;
}