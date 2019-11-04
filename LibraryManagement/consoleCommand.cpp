#include "ConsoleCommand.h"
#include <iostream>

using namespace std;

UserService userService;
BookService bookService;
TypeService typeService;
RecordService recordService;

void printMenu()
{
	cout << "*****欢迎使用图书馆管理系统!*****" << endl;
	cout << "**********系统功能如下：********" << endl;
	cout << "***********1-用户操作***********" << endl;
	cout << "***********2-书籍操作***********" << endl;
	cout << "**********3-借还书操作**********" << endl;
	cout << "*********4-书籍类别操作*********" << endl;
	cout << "***********0-退出系统***********" << endl;
}

void printFunction(int num)
{
	if (num == 1) // user
	{
		cout << "1-添加用户" << endl;
		cout << "2-删除用户" << endl;
		cout << "3-修改用户信息" << endl;
		cout << "4-查询用户信息" << endl;
		cout << "5-查询所有用户信息" << endl;
	}
	else if (num == 2) // book
	{
		cout << "1-增加图书" << endl;
		cout << "2-删除图书" << endl;
		cout << "3-修改图书信息" << endl;
		cout << "4-查询图书信息" << endl;
	}
	else if (num == 3) // borrow and return
	{
		cout << "1-借阅图书" << endl;
		cout << "2-归还图书" << endl;
		cout << "3-续借图书" << endl;
		cout << "4-显示所有用户借阅记录" << endl;
	}
	else if (num == 4) // book type
	{
		cout << "1-增加书籍类型" << endl;
		cout << "2-查询全部书籍类型" << endl;
	}
}

void addUser()
{
	User user;

	string id;
	string name;
	int type;

	cout << "请输入要添加的用户的学号：";
	cin >> id;
	user.setId(id);
	cout << "";
	cout << "请输入要添加的用户的姓名：";
	cin >> name;
	user.setName(name);

	cout << "请输入要添加的用户的类型（0-STUDENT,1-TEACHER）：";
	cin >> type;
	if (type == 0)
	{
		user.setType(User::STUDENT);
	}
	else if(type == 1)
	{
		user.setType(User::TEACHER);
	}
	else
	{
		cout << "输入类型错误！" << endl;
		return;
	}
	user.setStatus(User::NORMAL);
	int status = userService.addUser(user);
	if (status == UserService::SUCCESS)
	{
		cout << "添加用户成功！" << endl;
	}
	else if (status == UserService::USER_ALREADAY_EXIST)
	{
		cout << "用户已存在，添加失败！" << endl;
	}
	else
	{
		cout << "未知错误" << endl;
	}
}

void deleteUser()
{
	string id;
	cout << "请输入要被删除的用户的ID：";
	cin >> id;

	int status = userService.delUser(id);
	if (status == UserService::SUCCESS)
	{
		cout << "删除用户成功！" << endl;
	}
	else if(status == UserService::USER_NOT_FOUND)
	{
		cout << "用户不存在！删除失败！" << endl;
	}
	else
	{
		cout << "错误" << endl;
	}
}

void modifyUserInfo()
{
	string id;
	cout << "请输入您将修改信息的用户的ID";
	cin >> id;

	bool found = false;
	userService.findUserById(id, found);
	if (!found)
	{
		cout << "输入的用户id不存在！" << endl;
		return;
	}

	User user;
	user.setId(id);

	string name;
	int type;
	int status;

	cout << "请输入更改后的用户的姓名：";
	cin >> name;
	user.setName(name);

	cout << "请输入更改后的用户的类型（0-STUDENT,1-TEACHER）：";
	cin >> type;
	if (type == 0)
	{
		user.setType(User::STUDENT);
	}
	else if (type == 1)
	{
		user.setType(User::TEACHER);
	}
	else
	{
		cout << "类型输入错误！" << endl;
	}
	found;
	user.setStatus(userService.findUserById(id, found).getStatus());
	int s = userService.changeUserInfo(id, user);
	if (s == UserService::SUCCESS)
	{
		cout << "修改用户信息成功！" << endl;
	}
	else if(s == UserService::USER_NOT_FOUND)
	{
		cout << "输入的id不存在！修改用户信息失败！" << endl;
	}
	else
	{
		cout << "错误！修改用户信息失败！" << endl;
	}
}

void printUserInfo(User user)
{
	cout << "用户ID：" << user.getId() << endl;
	cout << "用户名：" << user.getName() << endl;
	cout << "用户类型：";
	if (user.getType() == 0)
	{
		cout << "学生" << endl;
	}
	else
	{
		cout << "教师" << endl;
	}
	cout << "用户状态：";
	if (user.getStatus() == User::NORMAL)
	{
		cout << "正常" << endl;
	}
	else if (user.getStatus() == User::DELETED)
	{
		cout << "被删除" << endl;
	}
	else if (user.getStatus() == User::FULL)
	{
		cout << "书已借满" << endl;
	}
	else
	{
		cout << "未知" << endl;
	}
	cout << endl;
}

void findUserById()
{
	string id;
	cout << "请输入您要查询的用户的ID";
	cin >> id;

	User user;
	bool found;
	user = userService.findUserById(id, found);
	if (!found)
	{
		cout << "此用户不存在！" << endl;
		return;
	}
	printUserInfo(user);
}

void findUserByName()
{
	string name;
	cout << "请输入您要查询用户的名字:";
	cin >> name;

	User user;
	bool found;
	user = userService.findUserByName(name, found); //暂时假定用户名不重，根据用户名查询到有且仅有一个用户，若用户不存在则打印用户不存在
	if (!found)
	{
		cout << "此用户不存在！" << endl;
		return;
	}
	printUserInfo(user);
}

void findOneUser()
{
	int choice;
	cout << "1-根据ID查询用户信息,2-根据用户名查询用户信息,请输入所需功能前面的编号：";
	cin >> choice;
	switch (choice)
	{
	case 1:
		findUserById();
		break;
	case 2:
		findUserByName();
		break;
	default:
		cout << "您输入的数字有误，请检查后再输入！" << endl;
	}
}

void findAllUser()
{
	vector<User> users = userService.findAllUser();
	if (users.size() == 0)
	{
		cout << "暂无任何用户!" << endl;
		return;
	}
	vector<User>::iterator it = users.begin();
	while (it != users.end())
	{
		printUserInfo(*it);
		it++;
	}
}

void addBook() //增加一类书
{
	Book book;

	int typeId;
	string name;
	string author;
	string publisher;
	string ISBN;
	double price;
	int quantity;

	cout << "请输入书籍的书名：";
	cin >> name;
	book.setName(name);

	cout << "请输入书籍的作者：";
	cin >> author;
	book.setAuthor(author);

	auto types = typeService.findAllType();
	if (types.size() == 0)
	{
		cout << "请先到主菜单中添加书籍类别！" << endl;
	}
	for (auto type : types)
	{
		cout << type.getId() << " " << type.getName() << "; ";
	}
	cout << endl;

	cout << "请输入书籍类型前面的数字代码：";
	cin >> typeId;
	bool found = false;
	typeService.findTypeById(typeId, found);
	if (!found)
	{
		cout << "输入的书籍类型代码有误！" << endl;
		return;
	}
	book.setTypeId(typeId);

	cout << "请输入书籍的出版社：";
	cin >> publisher;
	book.setPublisher(publisher);

	cout << "请输入书籍的ISBN：";
	cin >> ISBN;
	book.setISBN(ISBN);

	cout << "请输入书籍的价格：";
	cin >> price;
	book.setPrice(price);

	cout << "请输入书籍的数量：";
	cin >> quantity;
	book.setQuantity(quantity);

	book.setStatus(Book::NORMAL);

	if (bookService.addBook(book) == BookService::SUCCESS)
	{
		cout << "增加书籍成功！" << endl;
	}
	else
	{
		cout << "增加书籍失败！" << endl;
	}
}

void delBook()
{
	int id;
	cout << "请输入要删除书籍的ID：";
	cin >> id;

	if (bookService.delBook(id) == BookService::SUCCESS)
	{
		cout << "删除书籍成功！" << endl;
	}
	else if (bookService.delBook(id) == BookService::ERROR)
	{
		cout << "删除书籍失败！本书已被删除！" << endl;
	}
	else if (bookService.delBook(id) == BookService::BOOK_NOT_FOUND)
	{
		cout << "没有找到书籍！" << endl;
	}
}

void modifyBookInfo()
{
	Book book;
	int typeId;
	string name;
	string author;
	string publisher;
	string ISBN;
	double price;
	int quantity;
	int status;

	int id;
	cout << "请输入要修改的书籍编号：";
	cin >> id;
	book.setId(id);

	bool found = false;
	bookService.findBookById(id, found);
	if (!found)
	{
		cout << "输入的id不存在！" << endl;
	}

	cout << "请输入书籍的书名：";
	cin >> name;
	book.setName(name);

	cout << "请输入书籍的作者：";
	cin >> author;
	book.setAuthor(author);

	auto types = typeService.findAllType();
	if (types.size() == 0)
	{
		cout << "请先到主菜单中添加书籍类别！" << endl;
	}
	for (auto type : types)
	{
		cout << type.getId() << " " << type.getName() << "; ";
	}
	cout << endl;

	cout << "请输入书籍类型前面的数字代码：";
	cin >> typeId;
	found = false;
	typeService.findTypeById(typeId, found);
	if (!found)
	{
		cout << "输入的书籍类型代码有误！" << endl;
		return;
	}
	book.setTypeId(typeId);

	cout << "请输入书籍的出版社：";
	cin >> publisher;
	book.setPublisher(publisher);

	cout << "请输入书籍的ISBN：";
	cin >> ISBN;
	book.setISBN(ISBN);

	cout << "请输入书籍的价格：";
	cin >> price;
	book.setPrice(price);

	cout << "请输入书籍的数量：";
	cin >> quantity;
	book.setQuantity(quantity);

	cout << "请输入书籍的状态(0-NORMAL,1-DELETED)：";
	cin >> status;
	if (status == 0)
	{
		book.setStatus(Book::NORMAL);
	}
	else
	{
		book.setStatus(Book::DELETED);
	}

	if (bookService.changeBookInfo(id, book) == BookService::SUCCESS)
	{
		cout << "修改书籍信息成功！" << endl;
	}
	else if (bookService.changeBookInfo(id,book) == BookService::ERROR) 
	{
		cout << "修改书籍信息失败！" << endl;
	}
	else if (bookService.changeBookInfo(id, book) == BookService::BOOK_NOT_FOUND)
	{
		cout << "没有找到书籍！" << endl;
	}
}

void printBookInfo(Book book)
{
	bool found;
	cout << "书籍ID：" << book.getId() << endl;
	cout << "书籍类别：" << typeService.findTypeById(book.getTypeId(), found).getName() << endl;
	cout << "书名：" << book.getName() << endl;
	cout << "作者：" << book.getAuthor() << endl;
	cout << "出版社：" << book.getPublisher() << endl;
	cout << "ISBN:" << book.getISBN() << endl;
	cout << "价格：" << book.getPrice() << endl;
	cout << "总数：" << book.getQuantity() << endl;
	cout << "书籍状态：";
	if (book.getStatus() == Book::NORMAL)
	{
		cout << "正常" << endl;
	}
	else if (book.getStatus() == Book::DELETED)
	{
		cout << "删除" << endl;
	}
	cout << endl;
}

void findAllBook()
{
	vector<Book> books = bookService.findAllBook();
	vector<Book>::iterator it = books.begin();
	while (it != books.end())
	{
		printBookInfo(*it);
		it++;
	}
	cout << "查询所有书籍信息成功！" << endl;
}

void borrowBook()
{
	string userId;
	cout << "请输入用户ID：";
	cin >> userId;

	int bookId;
	cout << "请输入书籍ID：";
	cin >> bookId;

	bool found = false;
	Book book = bookService.findBookById(bookId, found);
	if (!found || book.getStatus() != Book::NORMAL)
	{
		cout << "输入的书籍id不存在！" << endl;
		return;
	}

	vector<ABookVo> aBookVoList = bookService.findABookByBookId(bookId);
	if (aBookVoList.size() == 0)
	{
		cout << "该书籍不存在！" << endl;
		return;
	}
	cout << "该类书所有单本如下：" << endl;
	for (ABookVo vo : aBookVoList)
	{
		cout << vo.getId() << " " << vo.getBookName() << " " << vo.getAuthor() << " " << vo.getPublisher() << " ";
		if (vo.getStatus() == ABook::NORMAL)
		{
			cout << "正常" << endl;
		}
		else if (vo.getStatus() == ABook::BORROWED)
		{
			cout << "被借阅" << endl;
		}
		else
		{
			cout << "非正常状态" << endl;
		}
		
	}

	int aBookId;
	cout << "请输入单本id：" << endl;
	cin >> aBookId;
	if (recordService.borrowBook(userId, aBookId) == RecordService::SUCCESS)
	{
		cout << "借书成功！" << endl;
	}
	else
	{
		cout << "借书失败！" << endl;
	}
}

void returnBook()
{
	string userId;
	cout << "请输入用户ID：";
	cin >> userId;

	int bookId;
	cout << "请输入待还书籍ID：";
	cin >> bookId;

	if (recordService.returnBook(userId, bookId) == RecordService::SUCCESS)
	{
		cout << "还书成功！" << endl;
	}
	else
	{
		cout << "还书失败！" << endl;
	}
}

void printRecord(RecordVo record)
{
	cout << "借阅记录编号：" << record.getId() << endl;
	cout << "借阅人：" << record.getUserName() << endl;
	cout << "书名：" << record.getBookName() << endl;
	cout << "借书时间：" << record.getDate() << endl;
	cout << "借书时长：" << record.getDuration() << "天" << endl;
	cout << "还书时间：" << record.getReturnDate() << endl;
	cout << "状态：";
	if (record.getStatus() == Record::NORMAL)
	{
		cout << "借阅中" << endl;
	}
	else if (record.getStatus() == Record::EXCEED)
	{
		cout << "超期" << endl;
	}
	else if (record.getStatus() == Record::DELETED)
	{
		cout << "已被删除" << endl;
	}
	else if (record.getStatus() == Record::RETURNED)
	{
		cout << "已还" << endl;
	}
	cout << endl;
}

void renewBook()
{
	string userId;
	cout << "请输入用户ID：";
	cin >> userId;

	int bookId;
	cout << "请输入书籍ID：";
	cin >> bookId;

	bool found;
	RecordVo record = recordService.findRecordByUserIdAndBookId(userId, bookId, found);
	printRecord(record);

	if (recordService.renewBook(record.getId(), record.getDuration()) == RecordService::SUCCESS)
	{
		cout << "续借成功！" << endl;
	}
	else
	{
		cout << "续借失败！" << endl;
	}
}

void findAllRecord()
{
	vector<RecordVo> records = recordService.findAllRecord();
	for (int i = 0; i < records.size(); ++i)
	{
		printRecord(records[i]);
	}
	cout << "查询所有用户借阅记录成功！" << endl;
}

void printBookTypeInfo(BookType bookType)
{
	cout << "图书类别代号：" << bookType.getId() << "  ";
	cout << "图书类别：" << bookType.getName() << endl;
}

void addBookType()
{
	BookType bookType;
	string newName;
	cout << "请输入您要增加的新类别的名称：";
	cin >> newName;
	bookType.setName(newName);
	if (typeService.insertType(bookType))
	{
		cout << "增加新类别成功！" << endl;
	}
	else
	{
		cout << "增加新类别失败！" << endl;
	}
}

void findAllBookType()
{
	vector<BookType> bookTypes = typeService.findAllType();
	for (int i = 0; i < bookTypes.size(); ++i)
	{
		printBookTypeInfo(bookTypes[i]);
	}
}

void console()
{
	printMenu();

	while (true)
	{
		cout << "请输入您要执行的操作编号：" << endl;
		int choice1;
		cin >> choice1;

		int choice2;
		switch (choice1)
		{
		case 0:
			cout << "系统已退出！" << endl;
			return;
		case 1:
			printFunction(1);

			cout << "请输入您要执行的子操作编号：" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				addUser();
				break;
			case 2:
				deleteUser();
				break;
			case 3:
				modifyUserInfo();
				break;
			case 4:
				findOneUser();
				break;
			case 5:
				findAllUser();
				break;
			default:
				cout << "您输入的数字有误，请检查后重新输入！" << endl;
			}

			break;
		case 2:
			printFunction(2);

			cout << "请输入您要执行的子操作编号：" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				addBook();
				break;
			case 2:
				delBook();
				break;
			case 3:
				modifyBookInfo();
				break;
			case 4:
				findAllBook();
				break;
			default:
				cout << "您输入的数字有误，请检查后重新输入！" << endl;
			}

			break;
		case 3:
			printFunction(3);

			cout << "请输入您要执行的子操作编号：" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				borrowBook();
				break;
			case 2:
				returnBook();
				break;
			case 3:
				renewBook();
				break;
			case 4:
				findAllRecord();
				break;
			default:
				cout << "您输入的数字有误，请检查后重新输入！" << endl;
			}

			break;
		case 4:
			printFunction(4);

			cout << "请输入您要执行的子操作编号：" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				addBookType();
				break;
			case 2:
				findAllBookType();
				break;
			default:
				cout << "您输入的数字有误，请检查后重新输入！" << endl;
			}

			break;
		default:
			cout << "您输入的数字有误，请检查后重新输入！" << endl;
		}
	}
}
