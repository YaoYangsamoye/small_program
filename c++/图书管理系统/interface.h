
#include"book.h"

void Face(Book *book);                //主界面
void Face_student(Book *book);         //学生界面
void Face_admin(Book *book);           //管理员界面
void select_book(Book *book);          //选择界面
void select_book1(Book *book);       //查询方式选择
void select_book2(Book *book);
void select_book3(Book* book);
void select_book4(Book* book);
void borrow_book(Book* book);        //借阅书籍
void return_book(Book* book);        //归还图书
void Face(Book *book)
{
	cout << "***************************************" << endl;
	cout << "*************主界面********************" << endl;
	cout << "*************1.管理员******************" << endl;
	cout << "*************2.普通读者****************" << endl;
	cout << "*************3.退出********************" << endl;
	cout << "***************************************" << endl;
	int a;
	cout << "请输入选项:";
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
			cout << "输入有误，请重新输入:" << endl;
			Face(book);
	}
}

void Face_student(Book *book)
{
	cout << "***************************************" << endl;
	cout << "*************1.查询图书****************" << endl;
	cout << "*************2.返回上级菜单************" << endl;
	cout << "*************3.退出********************" << endl;
	cout << "***************************************" << endl;
	int a;
	cout << "请输入选项:";
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
		cout << "输入有误，请重新输入:" << endl;
		Face_student(book);
	}
}
void Face_admin(Book *book)
{
	cout << "这是管理员界面，请输入密码:(默认admin)";
	string possward;
	cin >> possward;
	if (possward == "admin")
	{
		cout << "***************************************" << endl;
		cout << "*************1.添加图书****************" << endl;
		cout << "*************2.显示所有书籍*************" << endl;
		cout << "*************3.查询书籍****************" << endl;
		cout << "*************4.借阅书籍****************" << endl;
		cout << "*************5.归还书籍****************" << endl;
		cout << "*************6.退出********************" << endl;
		cout << "***************************************" << endl;
		int a;
		cout << "请输入选项:";
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
					cout << "添加完毕" << endl;
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
			cout << "归还成功！" << endl;
			Face(book);
		case 6:
			system("pause");
		default:
			cout << "输入有误，请重新输入:" << endl;
			Face(book);
		}
	}
	else
	{
		cout << "密码错误，返回主界面" << endl;
		Face(book);
	}
}
void select_book(Book *book)
{
	int a;
	cout << "****************************************" << endl;
	cout << "*************1.按名称查询***************" << endl;
	cout << "*************2.按编号查询***************" << endl;
	cout << "*************3.按姓名查询***************" << endl;
	cout << "*************4.按学号查询***************" << endl;
	cout << "*************5.返回上级菜单*************" << endl;
	cout << "*************6.退出*********************" << endl;
	cout << "****************************************" << endl;
	
	cout << "请输入选项:";
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
		cout << "输入有误，请重新输入:" << endl;
		select_book(book);
	}
}
void select_book1(Book *book)
{
	cout << "请输入图书的名称" << endl;
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
	cout << "请输入图书的编号" << endl;
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
	cout << "请输入学生的姓名" << endl;
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
	cout << "请输入学生的学号" << endl;
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
	cout << "请输入要借阅的书籍";
	string book_name,student_name, student_ID;
	cin >> book_name;
	for (int i = 0; i < sizeof(book); ++i)
	{
		if (book_name == book[i].return_Book_name())
		{
			book[i].Book_show(book);
			if (book[i].return_status() == true)
			{
				cout << "请输入借阅学生姓名：";
				cin >> student_name;
				book[i].add_student_name(student_name);
				cout << "请输入借阅学生学号：";
				cin >> student_ID;
				book[i].add_student_ID(student_ID);
				book[i].change_borrow();
				cout << "借阅完成" << endl;
				Face(book);
			}
		}
	}
}

void return_book(Book* book)
{
	cout << "请输入要归还的书籍";
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