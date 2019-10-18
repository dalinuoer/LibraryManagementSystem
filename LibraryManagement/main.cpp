#include <iostream>
#include <fstream>
#include "User.h"
#include "Book.h"
#include "Record.h"
#include "UserDao.h"
#include "BookDao.h"

using namespace std;

int main()
{
	User user;
	user.setId(1);
	user.setName("Hi");
	user.setType(User::STUDENT);
	user.setStatus(User::NORMAL);

	Book book;
	book.setId(1);
	book.setName("C++");
	book.setISBN("111111");
	book.setPrice(40);
	book.setPublisher("中国海洋大学出版社");
	book.setQuantity(30);
	book.setStatus(Book::NORMAL);
	
	
	UserDao userDao("data/User.dat");
	userDao.insertUser(user);

	user.setId(2);
	user.setName("Hello");
	userDao.insertUser(user);

	user.setId(3);
	user.setName("World");
	userDao.insertUser(user);

	user.setName("Hey");
	userDao.updateUser(3, user);

	BookDao bookDao("data/Book.dat");
	bookDao.insertBook(book);
	book.setName("数据结构");
	book.setId(2);
	bookDao.insertBook(book);
	bool found;
	Book book2=bookDao.findBookById(2,found);
	cout << book2.getId() << book2.getName();

	return 0;
}