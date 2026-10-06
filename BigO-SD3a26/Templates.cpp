#include <iostream>
#include "Pair.h"
using namespace std;

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();

int main()
{
	question4();
}
struct book
{
	string title;
	book(string s)
	{
		title = s;
	}
	book() {};
	bool operator>(book b1)
	{
		return title > b1.title;
	}
	friend ostream& operator<<(ostream& out, book b)
	{
		return out << b.title;
	}
};
template <class T>
T greaterThan(T x, T y)
{
	T largest = x > y ? x : y;
	return largest;
}

void question1()
{
	int ix = 5, iy = 10;
	cout << "The largest int is " << greaterThan(ix, iy)<<endl;
	char cx = 'a', cy = 'f';
	cout << "The largest char is " << greaterThan(cx, cy) << endl;
	book b1("The hobbit"), b2("The war of ard");
	cout << "The largest book is " << greaterThan(b1, b2) << endl;

}

template <class T>
T lessThan(T x, T y)
{
	T smallest = x > y ? y : x;
	return smallest;
}

void question2()
{
	int ix = 5, iy = 10;
	cout << "The smallest int is " << lessThan(ix, iy) << endl;
	char cx = 'a', cy = 'f';
	cout << "The smallest char is " << lessThan(cx, cy) << endl;
	book b1("The hobbit"), b2("The war of ard");
	cout << "The smallest book is " << lessThan(b1, b2) << endl;

}

template <class T>
void print(T* arr, int size)
{
	cout << "[";
	for (int i = 0; i < size;i++)
	{
		if (i != 0)
			cout << ",";
		cout << arr[i];
	}
	cout << "]" << endl;
}

void question3()
{
	int arr[5] = { 1,2,3,4,5 };
	print(arr, 5);
	book arrBook[5] = { book("The hobbit"), book("The judges list"),
			book("Harry potter"), book("The lightening theif"),
		book("The christmas pig") };
	print(arrBook, 5);
}

void question4()
{
	Pair<int, string> p1(1, "One");
	Pair<string, string> p2("Hello", "Greeting");
	Pair<int, book> p3(1, book("One flew over the cuckoos nest"));
	cout << p1 << p2 << p3 << endl;
}