#include "consoleCommand.h"
#include "User.h"
#include "Book.h"
#include "BookType.h"
#include "ABook.h"
#include "Record.h"
#include "UserDao.h"
#include <iostream>

using namespace std;

void printMenu()
{
	cout << "*****欢迎使用图书馆管理系统!*****" << endl;
	cout << "**********系统功能如下**********" << endl;
	cout << "***********1-用户操作***********" << endl;
	cout << "***********2-书籍操作***********" << endl;
	cout << "**********3-借还书操作**********" << endl;
	cout << "***********0-退出系统***********" << endl;
}

void printFunction(int num)
{
	if (num == 1)	// user
	{
		cout << "      1-添加用户       " << endl;
		cout << "      2-删除用户       " << endl;
		cout << "    3-修改用户信息     " << endl;
		cout << "    4-查询用户信息     " << endl;
		cout << "  5-查询所有用户信息   " << endl;
	}
	else if (num == 2)	// book
	{
		cout << "      1-增加图书       " << endl;
		cout << "      2-删除图书       " << endl;
		cout << "    3-修改图书信息     " << endl;
		cout << "    4-查询图书信息     " << endl;
	}
	else if (num == 3)	// borrow and return
	{
		cout << "      1-借阅图书       " << endl;
		cout << "      2-归还图书       " << endl;
		cout << "      3-续借图书       " << endl;
	}
}

void addUser()
{
	User user;

	string name;
	int type;

	cout << "请输入要添加的用户的姓名：";
	cin >> name;
	user.setName(name);

	cout << "请输入要添加的用户的类型（0-STUDENT,1-TEACHER）：";
	cin >> type;
	if (type == 0)
	{
		user.setType(User::STUDENT);
	}
	else
	{
		user.setType(User::TEACHER);
	}
	
	//UserService userService;
	//userService.insertUser(user);
}

void deleteUser()
{
	int id;
	cout << "请输入要被删除的用户的ID：";
	cin >> id;

	//UserService userService;
	//userService.delUser(id);
}

void modifyUserInfo()
{
	int id;
	cout << "请输入您将修改信息的用户的ID";
	cin >> id;

	User user;

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
	else
	{
		user.setType(User::TEACHER);
	}

	cout << "请输入更改后的用户的状态（0-NORMAL,1-DELETED,2-FULL）：";
	cin >> status;
	if (status == 0)
	{
		user.setStatus(User::NORMAL);
	}
	else if (status == 1)
	{
		user.setStatus(User::DELETED);
	}
	else
	{
		user.setStatus(User::FULL);
	}

	//UserService userService;
	//userService.changeUseInfo(id,user);
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
	if (user.getStatus() == 0)
	{
		cout << "正常" << endl;
	}
	else if (user.getStatus() == 1)
	{
		cout << "被删除" << endl;
	}
	else
	{
		cout << "书已借满" << endl;
	}
}

void findUserById()
{
	int id;
	cout << "请输入您要查询的用户的ID";
	cin >> id;

	User user;
	//UserService userService;
	//user = userService.findUserById(id);
	printUserInfo(user);
}

void findUserByName()
{
	string name;
	cout << "请输入您要查询用户的名字:";
	cin >> name;

	User user;
	//UserService userService;
	//user = userService.findUserByName(name);
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
	//UserService userService;
	//Vector<User> users = userService.findAllUser();
	//vector<User>::iterator it = users.begin();
	//while (it != users.end()) 
	//{
	//	printUserInfo(users[it]);
	//	it++;
	//}
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

			cout << "请输入您要执行的操作编号：" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				addUser();
				cout << "添加用户成功！" << endl;
				break;
			case 2:
				deleteUser();
				cout << "删除用户成功！" << endl;
				break;
			case 3:
				modifyUserInfo();
				cout << "修改用户信息成功！" << endl;
				break;
			case 4:
				findOneUser();
				cout << "查询用户信息成功！" << endl;
				break;
			case 5:
				findAllUser();
				cout << "查询所有用户信息成功！" << endl;
				break;
			default:
				cout << "您输入的数字有误，请检查后重新输入！" << endl;
			}

			break;
		case 2:
			printFunction(2);

			cout << "请输入您要执行的操作编号：" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				cout << "增加书籍成功！" << endl;
				break;
			case 2:
				cout << "删除书籍成功！" << endl;
				break;
			case 3:
				cout << "修改书籍信息成功！" << endl;
				break;
			case 4:
				cout << "查询书籍信息成功！" << endl;
				break;
			default:
				cout << "您输入的数字有误，请检查后重新输入！" << endl;
			}

			break;
		case 3:
			printFunction(3);

			cout << "请输入您要执行的操作编号：" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				cout << "借书成功" << endl;
				break;
			case 2:
				cout << "还书成功！" << endl;
				break;
			case 3:
				cout << "续借成功！" << endl;
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