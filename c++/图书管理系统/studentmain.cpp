

#include"interface.h"

# define book_number 5   //自定义图书数量
int main()
{
	Book* book = new Book[book_number];
	book[0].Book_init("c++第六版", "1", "20171003", "书架第二层", "20191003", "20191010", false,"张三","B16040330");
	book[1].Book_init("深入理解计算机系统", "2", "20171003", "书架第二层", "20191009", "20191010", false,"李四","B16040331");
	book[2].Book_init("牛津汉语词典", "3", "20171003", "书架第二层", "0", "0", true,"0","0"); 
	
	Face(book);
	system("pause");
}