#include<iostream>
#include"book.h"
using namespace std;
Book::Book()
{
	Book_ID = "0";
}
void Book::add_Book( )
{

	cout << "请输入图书的名字" << endl;
	cin >> Book_name;
	cout << "请输入图书的编号" << endl;
	cin >> Book_ID;
	cout << "请输入图书的存放地点" << endl;
	cin>> Book_location;
	cout << "请输入图书的收录时间(例如:20100201)" << endl;
	cin >> init_time;
	Borrow_time =" ";
	Deal_time = " ";
	Student_name = "";
	Student_ID = "";
	Borrow = true;
}

void Book::Book_show(Book *book)
{
	
	
		cout << "图书的名字：" << Book_name << endl;
		cout << "图书的编号：" << Book_ID << endl;
		cout << "图书的存放地点：" << Book_location << endl;
		cout << "图书的收录时间：" << init_time << endl;
		if (Borrow == false)
		{
			cout << "图书的借出时间：" << Borrow_time << endl;
			cout << "图书的归还时间：" << Deal_time << endl;
			cout << "借阅学生姓名：" << Student_name << endl;
			cout << "借阅学生学号：" << Student_ID << endl;
		}
		else
		{
			cout << "借阅状态：可借阅" << endl;
		}
		cout << endl;
	
	

}

void Book::Book_init(string name, string ID, string time, string location , string borrow_time , string deal_time , bool borrow, string student_name, string student_ID)
{
	Book_name = name;
	Book_ID = ID;
	init_time = time;
	Book_location = location;
	Borrow_time = borrow_time;
	Deal_time = deal_time;
	Borrow = borrow;
	Student_name = student_name;
	Student_ID = student_ID;

}

string Book::return_Book_name()
{
	return Book_name;
}
string  Book::return_Book_ID()
{
	return Book_ID;
}
string  Book::return_Student_name()
{
	return Student_name;
}
string  Book::return_Student_ID()
{
	return Student_ID;
}
bool Book::return_status()
{
	return Borrow;
}
void  Book::add_student_name(string student_name)
{
	Student_name = student_name;
}
void  Book::add_student_ID(string student_id)
{
	Student_ID = student_id;
}
void  Book::change_borrow()
{
	switch (Borrow)
	{
	case false:
		Borrow = true;
		break;
	case true:
		Borrow = false;
		break;
	}
}