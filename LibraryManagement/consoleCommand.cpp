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
	cout << "*****��ӭʹ��ͼ��ݹ���ϵͳ!*****" << endl;
	cout << "**********ϵͳ��������**********" << endl;
	cout << "***********1-�û�����***********" << endl;
	cout << "***********2-�鼮����***********" << endl;
	cout << "**********3-�軹�����**********" << endl;
	cout << "***********0-�˳�ϵͳ***********" << endl;
}

void printFunction(int num)
{
	if (num == 1)	// user
	{
		cout << "      1-����û�       " << endl;
		cout << "      2-ɾ���û�       " << endl;
		cout << "    3-�޸��û���Ϣ     " << endl;
		cout << "    4-��ѯ�û���Ϣ     " << endl;
		cout << "  5-��ѯ�����û���Ϣ   " << endl;
	}
	else if (num == 2)	// book
	{
		cout << "      1-����ͼ��       " << endl;
		cout << "      2-ɾ��ͼ��       " << endl;
		cout << "    3-�޸�ͼ����Ϣ     " << endl;
		cout << "    4-��ѯͼ����Ϣ     " << endl;
	}
	else if (num == 3)	// borrow and return
	{
		cout << "      1-����ͼ��       " << endl;
		cout << "      2-�黹ͼ��       " << endl;
		cout << "      3-����ͼ��       " << endl;
	}
}

void addUser()
{
	User user;

	string name;
	int type;

	cout << "������Ҫ��ӵ��û���������";
	cin >> name;
	user.setName(name);

	cout << "������Ҫ��ӵ��û������ͣ�0-STUDENT,1-TEACHER����";
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
	cout << "������Ҫ��ɾ�����û���ID��";
	cin >> id;

	//UserService userService;
	//userService.delUser(id);
}

void modifyUserInfo()
{
	int id;
	cout << "�����������޸���Ϣ���û���ID";
	cin >> id;

	User user;

	string name;
	int type;
	int status;

	cout << "��������ĺ���û���������";
	cin >> name;
	user.setName(name);

	cout << "��������ĺ���û������ͣ�0-STUDENT,1-TEACHER����";
	cin >> type;
	if (type == 0)
	{
		user.setType(User::STUDENT);
	}
	else
	{
		user.setType(User::TEACHER);
	}

	cout << "��������ĺ���û���״̬��0-NORMAL,1-DELETED,2-FULL����";
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
	cout << "�û�ID��" << user.getId() << endl;
	cout << "�û�����" << user.getName() << endl;
	cout << "�û����ͣ�";
	if (user.getType() == 0)
	{
		cout << "ѧ��" << endl;
	}
	else
	{
		cout << "��ʦ" << endl;
	}
	cout << "�û�״̬��";
	if (user.getStatus() == 0)
	{
		cout << "����" << endl;
	}
	else if (user.getStatus() == 1)
	{
		cout << "��ɾ��" << endl;
	}
	else
	{
		cout << "���ѽ���" << endl;
	}
}

void findUserById()
{
	int id;
	cout << "��������Ҫ��ѯ���û���ID";
	cin >> id;

	User user;
	//UserService userService;
	//user = userService.findUserById(id);
	printUserInfo(user);
}

void findUserByName()
{
	string name;
	cout << "��������Ҫ��ѯ�û�������:";
	cin >> name;

	User user;
	//UserService userService;
	//user = userService.findUserByName(name);
	printUserInfo(user);
}

void findOneUser()
{
	int choice;
	cout << "1-����ID��ѯ�û���Ϣ,2-�����û�����ѯ�û���Ϣ,���������蹦��ǰ��ı�ţ�";
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
		cout << "�������������������������룡" << endl;
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
		cout << "��������Ҫִ�еĲ�����ţ�" << endl;
		int choice1;
		cin >> choice1;

		int choice2;
		switch (choice1)
		{
		case 0:
			cout << "ϵͳ���˳���" << endl;
			return;
		case 1:
			printFunction(1);

			cout << "��������Ҫִ�еĲ�����ţ�" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				addUser();
				cout << "����û��ɹ���" << endl;
				break;
			case 2:
				deleteUser();
				cout << "ɾ���û��ɹ���" << endl;
				break;
			case 3:
				modifyUserInfo();
				cout << "�޸��û���Ϣ�ɹ���" << endl;
				break;
			case 4:
				findOneUser();
				cout << "��ѯ�û���Ϣ�ɹ���" << endl;
				break;
			case 5:
				findAllUser();
				cout << "��ѯ�����û���Ϣ�ɹ���" << endl;
				break;
			default:
				cout << "���������������������������룡" << endl;
			}

			break;
		case 2:
			printFunction(2);

			cout << "��������Ҫִ�еĲ�����ţ�" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				cout << "�����鼮�ɹ���" << endl;
				break;
			case 2:
				cout << "ɾ���鼮�ɹ���" << endl;
				break;
			case 3:
				cout << "�޸��鼮��Ϣ�ɹ���" << endl;
				break;
			case 4:
				cout << "��ѯ�鼮��Ϣ�ɹ���" << endl;
				break;
			default:
				cout << "���������������������������룡" << endl;
			}

			break;
		case 3:
			printFunction(3);

			cout << "��������Ҫִ�еĲ�����ţ�" << endl;
			cin >> choice2;

			switch (choice2)
			{
			case 1:
				cout << "����ɹ�" << endl;
				break;
			case 2:
				cout << "����ɹ���" << endl;
				break;
			case 3:
				cout << "����ɹ���" << endl;
				break;
			default:
				cout << "���������������������������룡" << endl;
			}

			break;
		default:
			cout << "���������������������������룡" << endl;
		}
	}
}