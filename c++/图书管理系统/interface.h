
#include"book.h"

void Face(Book *book);                //������
void Face_student(Book *book);         //ѧ������
void Face_admin(Book *book);           //����Ա����
void select_book(Book *book);          //ѡ�����
void select_book1(Book *book);       //��ѯ��ʽѡ��
void select_book2(Book *book);
void select_book3(Book* book);
void select_book4(Book* book);
void borrow_book(Book* book);        //�����鼮
void return_book(Book* book);        //�黹ͼ��
void Face(Book *book)
{
	cout << "***************************************" << endl;
	cout << "*************������********************" << endl;
	cout << "*************1.����Ա******************" << endl;
	cout << "*************2.��ͨ����****************" << endl;
	cout << "*************3.�˳�********************" << endl;
	cout << "***************************************" << endl;
	int a;
	cout << "������ѡ��:";
	cin >> a;
	cout << endl;
	switch (a)
	{
		case 1:
			Face_admin(book);
		case 2:
			Face_student(book);
		case 3:
			system("pause");
		default:
			cout << "������������������:" << endl;
			Face(book);
	}
}

void Face_student(Book *book)
{
	cout << "***************************************" << endl;
	cout << "*************1.��ѯͼ��****************" << endl;
	cout << "*************2.�����ϼ��˵�************" << endl;
	cout << "*************3.�˳�********************" << endl;
	cout << "***************************************" << endl;
	int a;
	cout << "������ѡ��:";
	cin >> a;
	cout << endl;
	switch (a)
	{
	case 1:
		select_book(book);
	case 2:
		Face(book);
	case 3:
		system("pause");
	default:
		cout << "������������������:" << endl;
		Face_student(book);
	}
}
void Face_admin(Book *book)
{
	cout << "���ǹ���Ա���棬����������:(Ĭ��admin)";
	string possward;
	cin >> possward;
	if (possward == "admin")
	{
		cout << "***************************************" << endl;
		cout << "*************1.���ͼ��****************" << endl;
		cout << "*************2.��ʾ�����鼮*************" << endl;
		cout << "*************3.��ѯ�鼮****************" << endl;
		cout << "*************4.�����鼮****************" << endl;
		cout << "*************5.�黹�鼮****************" << endl;
		cout << "*************6.�˳�********************" << endl;
		cout << "***************************************" << endl;
		int a;
		cout << "������ѡ��:";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
			for (int i = 0; i <sizeof(book); ++i)
			{
				if (book[i].return_Book_ID() =="0")
				{
					book[i].add_Book();
					cout << "������" << endl;
					Face(book);
				}
			}
		case 2:
			for (int i = 0; i < sizeof(book); ++i)
			{
				if (book[i].return_Book_ID() != "0")
				{
					book[i].Book_show(book);
				}
			}
			Face(book);
		case 3:
			select_book(book);
		case 4:

			borrow_book(book);
		case 5:
			return_book(book);
			cout << "�黹�ɹ���" << endl;
			Face(book);
		case 6:
			system("pause");
		default:
			cout << "������������������:" << endl;
			Face(book);
		}
	}
	else
	{
		cout << "������󣬷���������" << endl;
		Face(book);
	}
}
void select_book(Book *book)
{
	int a;
	cout << "****************************************" << endl;
	cout << "*************1.�����Ʋ�ѯ***************" << endl;
	cout << "*************2.����Ų�ѯ***************" << endl;
	cout << "*************3.��������ѯ***************" << endl;
	cout << "*************4.��ѧ�Ų�ѯ***************" << endl;
	cout << "*************5.�����ϼ��˵�*************" << endl;
	cout << "*************6.�˳�*********************" << endl;
	cout << "****************************************" << endl;
	
	cout << "������ѡ��:";
	cin >> a;
	cout<<endl;
	switch (a)
	{
	case 1:
		select_book1(book);
		break;
	case 2:
		select_book2(book);
		break;
	case 3:
		select_book3(book);
		break;
	case 4:
		select_book4(book);
		break;
	case 5:
		Face(book);
		break;
	case 6:
		system("pause");
		break;
	default:
		cout << "������������������:" << endl;
		select_book(book);
	}
}
void select_book1(Book *book)
{
	cout << "������ͼ�������" << endl;
	string name;
	cin>>name;
	for (int i = 0; i < sizeof(book); ++i)
	{
		
		if (name ==book[i].return_Book_name() )
		{
			book[i].Book_show(book);
		}
	}
	cout << endl;
	select_book(book);
}
void select_book2(Book *book)
{
	cout << "������ͼ��ı��" << endl;
	string ID;
	cin >> ID;

	for (int i = 0; i < sizeof(book); ++i)
	{
		if (book[i].return_Book_ID() == ID)
		{
			book[i].Book_show(book);
		}
	}
	cout << endl;
	select_book(book);
}

void select_book3(Book* book)
{
	cout << "������ѧ��������" << endl;
	string name;
	cin >> name;

	for (int i = 0; i < sizeof(book); ++i)
	{
		if (book[i].return_Student_name()==name)
		{
			book[i].Book_show(book);
		}
	}
	cout << endl;
	select_book(book);
}

void select_book4(Book* book)
{
	cout << "������ѧ����ѧ��" << endl;
	string ID;
	cin >> ID;

	for (int i = 0; i < sizeof(book); ++i)
	{
		if (book[i].return_Student_ID()== ID)
		{
			book[i].Book_show(book);
		}
	}
	cout << endl;
	select_book(book);
}

void borrow_book(Book* book)
{
	cout << "������Ҫ���ĵ��鼮";
	string book_name,student_name, student_ID;
	cin >> book_name;
	for (int i = 0; i < sizeof(book); ++i)
	{
		if (book_name == book[i].return_Book_name())
		{
			book[i].Book_show(book);
			if (book[i].return_status() == true)
			{
				cout << "���������ѧ��������";
				cin >> student_name;
				book[i].add_student_name(student_name);
				cout << "���������ѧ��ѧ�ţ�";
				cin >> student_ID;
				book[i].add_student_ID(student_ID);
				book[i].change_borrow();
				cout << "�������" << endl;
				Face(book);
			}
		}
	}
}

void return_book(Book* book)
{
	cout << "������Ҫ�黹���鼮";
	string book_name;
	cin >> book_name;
	for (int i = 0; i < sizeof(book); ++i)
	{
		if (book_name == book[i].return_Book_name())
		{
			book[i].Book_show(book);
			book[i].change_borrow();
		}
	}
}