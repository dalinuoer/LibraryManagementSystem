#include "ConsoleCommand.h"
#include <iostream>

using namespace std;

void printMenu()
{
	cout << "*****��ӭʹ��ͼ��ݹ���ϵͳ!*****" << endl;
	cout << "**********ϵͳ�������£�********" << endl;
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

UserService userService;

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
	
	if (userService.addUser(user))
	{
		cout << "����û��ɹ���" << endl;
	}
	else
	{
		cout << "����û�ʧ�ܣ�" << endl;
	}
}

void deleteUser()
{
	int id;
	cout << "������Ҫ��ɾ�����û���ID��";
	cin >> id;
	
	if (userService.delUser(id))
	{
		cout << "ɾ���û��ɹ���" << endl;
	}
	else
	{
		cout << "ɾ���û�ʧ�ܣ�" << endl;
	}
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

	
	if (userService.changeUserInfo(id, user))
	{
		cout << "�޸��û���Ϣ�ɹ���" << endl;
	}
	else
	{
		cout << "�޸��û���Ϣʧ�ܣ�" << endl;
	}
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
	if (user.getStatus() == User::NORMAL)
	{
		cout << "����" << endl;
	}
	else if (user.getStatus() == User::DELETED)
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
	bool found;
	user = userService.findUserById(id, found);
	if (!found)
	{
		cout << "���û������ڣ�" << endl;
		return;
	}
	printUserInfo(user);
	cout << "��ѯ�û���Ϣ�ɹ���" << endl;
}

void findUserByName()
{
	string name;
	cout << "��������Ҫ��ѯ�û�������:";
	cin >> name;

	User user;
	bool found;
	user = userService.findUserByName(name, found);//��ʱ�ٶ��û������أ������û�����ѯ�����ҽ���һ���û������û����������ӡ�û�������
	if (!found)
	{
		cout << "���û������ڣ�" << endl;
		return;
	}
	printUserInfo(user);
	cout << "��ѯ�û���Ϣ�ɹ���" << endl;
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
	vector<User> users = userService.findAllUser();
	vector<User>::iterator it = users.begin();
	while (it != users.end()) 
	{
		printUserInfo(*it);
		it++;
	}
	
	cout << "��ѯ�ɹ�"<< endl;
}

BookService bookService;
TypeService typeService;

void addBook()//����һ����
{
	Book book;

	int typeId;
	string name;
	string author;
	string publisher;
	string ISBN;
	double price;
	int quantity;

	cout << "�������鼮��������";
	cin >> name;
	book.setName(name);

	cout << "�������鼮�����ߣ�";
	cin >> author;
	book.setAuthor(author);
	
	typeService.findAllType();
	cout << "�������鼮����ǰ������ִ��룺";
	cin >> typeId;
	book.setTypeId(typeId);
	
	cout << "�������鼮�ĳ����磺";
	cin >> publisher;
	book.setPublisher(publisher);

	cout << "�������鼮��ISBN��";
	cin >> ISBN;
	book.setISBN(ISBN);

	cout << "�������鼮�ļ۸�";
	cin >> price;
	book.setPrice(price);

	cout << "�������鼮��������";
	cin >> quantity;
	book.setQuantity(quantity);

	book.setStatus(Book::NORMAL);
	
	if (bookService.addBook(book))
	{
		cout << "�����鼮�ɹ���" << endl;
	}
	else
	{
		cout << "�����鼮ʧ�ܣ�" << endl;
	}
}

void delBook()
{
	int id;
	cout << "������Ҫɾ���鼮��ID��";
	cin >> id;
	
	if (bookService.delBook(id))
	{
		cout << "ɾ���鼮�ɹ���" << endl;
	}
	else
	{
		cout << "ɾ���鼮ʧ�ܣ�" << endl;
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
	cout << "������Ҫ�޸ĵ��鼮��ţ�";
	cin >> id;

	cout << "�������鼮��������";
	cin >> name;
	book.setName(name);

	cout << "�������鼮�����ߣ�";
	cin >> author;
	book.setAuthor(author);
	
	typeService.findAllType();
	cout << "�������鼮����ǰ������ִ��룺";
	cin >> typeId;
	book.setTypeId(typeId);
	
	cout << "�������鼮�ĳ����磺";
	cin >> publisher;
	book.setPublisher(publisher);

	cout << "�������鼮��ISBN��";
	cin >> ISBN;
	book.setISBN(ISBN);

	cout << "�������鼮�ļ۸�";
	cin >> price;
	book.setPrice(price);

	cout << "�������鼮��������";
	cin >> quantity;
	book.setQuantity(quantity);

	cout << "�������鼮��״̬(0-NORMAL,1-DELETED)��";
	cin >> status;
	if (status == 0)
	{
		book.setStatus(Book::NORMAL);
	}
	else
	{
		book.setStatus(Book::DELETED);
	}

	if (bookService.changeBookInfo(id, book))
	{
		cout << "�޸��鼮��Ϣ�ɹ���" << endl;
	}
	else
	{
		cout << "�޸��鼮��Ϣʧ�ܣ�" << endl;
	}
}
void printBookInfo(Book book)
{
	bool found;
	cout << "�鼮ID��" << book.getId() << endl;
	cout << "�鼮���" << typeService.findTypeById(book.getTypeId(), found).getName() << endl;
	cout << "������" << book.getName() << endl;
	cout << "���ߣ�" << book.getAuthor() << endl;
	cout << "�����磺" << book.getPublisher() << endl;
	cout << "ISBN:" << book.getISBN() << endl;
	cout << "�۸�" << book.getPrice() << endl;
	cout << "������" << book.getQuantity() << endl;
	cout << "�鼮״̬��";
	if (book.getStatus() == 0)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "ɾ��" << endl;
	}
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
	cout << "��ѯ�����鼮��Ϣ�ɹ���" << endl;
}

RecordService recordService;

void borrowBook()
{
	int userId;
	cout << "�������û�ID��";
	cin >> userId;

	int bookId;
	cout << "�������鼮ID��";
	cin >> bookId;

	if (recordService.borrowBook(userId, bookId))
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
}

void returnBook()
{
	int userId;
	cout << "�������û�ID��";
	cin >> userId;

	int bookId;
	cout << "����������鼮ID��";
	cin >> bookId;

	if (recordService.returnBook(userId, bookId))
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
	}
}

void printRecord(Record record)
{
	cout << "�鼮ID:" << record.getBookId() << endl;
	cout << "�û�ID:" << record.getUserId() << endl;
	cout << "����ʱ��:" << record.getDate() << endl;
	cout << "����ʱ��:" << record.getDuration() << endl;
}

void renewBook()
{
	int userId;
	cout << "�������û�ID��";
	cin >> userId;

	int bookId;
	cout << "�������鼮ID��";
	cin >> bookId;

	bool found;
	Record record = recordService.findRecordByUserIdAndBookId(userId, bookId, found);
	printRecord(record);

	if (recordService.renewBook(record.getId(), record.getDuration()))
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ�" << endl;
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
				borrowBook();
				break;
			case 2:
				returnBook();
				break;
			case 3:
				renewBook();
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