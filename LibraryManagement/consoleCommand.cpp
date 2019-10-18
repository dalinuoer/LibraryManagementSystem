#include "consoleCommand.h"
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
				cout << "添加用户成功！" << endl;
				break;
			case 2:
				cout << "删除用户成功！" << endl;
				break;
			case 3:
				cout << "修改用户信息成功！" << endl;
				break;
			case 4:
				cout << "查询用户信息成功！" << endl;
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