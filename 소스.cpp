#include<iostream>
#include<cstring>
using namespace std;

class Book
{
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* mytitle, const char* myisbn, int price) :price(price)
	{
		title = new char[strlen(mytitle) + 1];
		strcpy(title, mytitle);
		isbn = new char[strlen(myisbn) + 1];
		strcpy(isbn, myisbn);
	}
	void ShowBookInfo()
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class EBook :public Book
{
	char* DRMKey;
public:
	EBook(const char* mytitle, const char* myisbn, int price, const char* mydrm) :Book(mytitle, myisbn, price)
	{
		DRMKey = new char[strlen(mydrm) + 1];
		strcpy(DRMKey, mydrm);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[]DRMKey;
	}
};

int main()
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}

//_CRT_SECURE_NO_WARNINGS �ڿ� ;�� ���δ�.