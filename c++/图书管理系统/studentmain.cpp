

#include"interface.h"

# define book_number 5   //�Զ���ͼ������
int main()
{
	Book* book = new Book[book_number];
	book[0].Book_init("c++������", "1", "20171003", "��ܵڶ���", "20191003", "20191010", false,"����","B16040330");
	book[1].Book_init("�����������ϵͳ", "2", "20171003", "��ܵڶ���", "20191009", "20191010", false,"����","B16040331");
	book[2].Book_init("ţ����ʵ�", "3", "20171003", "��ܵڶ���", "0", "0", true,"0","0"); 
	
	Face(book);
	system("pause");
}