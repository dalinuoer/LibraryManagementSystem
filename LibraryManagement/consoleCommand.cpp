#include "consoleCommand.h"
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
				cout << "����û��ɹ���" << endl;
				break;
			case 2:
				cout << "ɾ���û��ɹ���" << endl;
				break;
			case 3:
				cout << "�޸��û���Ϣ�ɹ���" << endl;
				break;
			case 4:
				cout << "��ѯ�û���Ϣ�ɹ���" << endl;
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