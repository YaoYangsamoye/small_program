#include<iostream>
#include<string>

using namespace std;
class Book
{
private:
	string Book_name;
	string Book_ID;
	string init_time;
	string Book_location;
	string Borrow_time;
	string Deal_time;
	string Student_name;
    string Student_ID;
	bool Borrow;   //true为没有借出
public:
	
	
	Book();
	void Book_init(string name, string ID, string time, string location, string borrow_time, string deal_time, bool borrow, string Student_name, string Student_ID);
	void add_Book();
	void Book_show(Book* book);
	string return_Book_name();
	string return_Book_ID();
	string return_Student_name();
	string return_Student_ID();
	bool return_status();
	void add_student_name(string student_name);
	void add_student_ID(string student_id);
	void change_borrow();

};