#include<iostream>
#include"book.h"
using namespace std;
Book::Book()
{
	Book_ID = "0";
}
void Book::add_Book( )
{

	cout << "������ͼ�������" << endl;
	cin >> Book_name;
	cout << "������ͼ��ı��" << endl;
	cin >> Book_ID;
	cout << "������ͼ��Ĵ�ŵص�" << endl;
	cin>> Book_location;
	cout << "������ͼ�����¼ʱ��(����:20100201)" << endl;
	cin >> init_time;
	Borrow_time =" ";
	Deal_time = " ";
	Student_name = "";
	Student_ID = "";
	Borrow = true;
}

void Book::Book_show(Book *book)
{
	
	
		cout << "ͼ������֣�" << Book_name << endl;
		cout << "ͼ��ı�ţ�" << Book_ID << endl;
		cout << "ͼ��Ĵ�ŵص㣺" << Book_location << endl;
		cout << "ͼ�����¼ʱ�䣺" << init_time << endl;
		if (Borrow == false)
		{
			cout << "ͼ��Ľ��ʱ�䣺" << Borrow_time << endl;
			cout << "ͼ��Ĺ黹ʱ�䣺" << Deal_time << endl;
			cout << "����ѧ��������" << Student_name << endl;
			cout << "����ѧ��ѧ�ţ�" << Student_ID << endl;
		}
		else
		{
			cout << "����״̬���ɽ���" << endl;
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