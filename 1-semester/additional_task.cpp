//Вариант 5. Сведения о книгах. Классы.

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Book
{
public:
	int UDC;//УДК номер
	string Author; //Автор ФИО
	string Name; //название книги
	int Year; //год издания
	int Amount; //кол-во экземпляров данной книги в библиотеке

public:
	void SetUDC() //удк номер
	{
		cout<< endl << "Введите номер УДК: ";
		cin >> UDC;
	}

	void SetAuthor() //автор фио
	{
		cout << endl << "Введите ФИО автора: ";
		cin >> Author;
	}

	void SetName() //название
	{
		cout << endl << "Введите название книги: ";
		cin >> Name;
	}

	void SetYear() //год издания
	{
		cout << endl << "Введите год издания: ";
		cin >> Year;
	}

	void SetAmount() //кол-во экземпляров данной книги в библиотеке
	{
		cout << endl << "Введите кол-во экземляров: ";
		cin >> Amount;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Библиотекарь рад Вас видеть!!!" << endl;
	vector <string> vAuthor; //Автор ФИО
	vector <string> vName; //название книги
	vector <int> vYear; //год издания

	map <int, int> amount; //при вводе удк(первое) выводится кол-вл(второе)

	Book B;

	int books;
	cout << "Сколько книг вы хотите добавить ";
	cin >> books;
	if (books <= 0) //не надо -3 книги вводить!
		return 0;

	int i;
	for (i = books; i > 0; i--)
	{
		B.SetUDC();
		B.SetAmount();
		amount[B.UDC] = B.Amount; //в словарь добавляем удк, которому соотв. опред.кол-во экземляров
		B.SetAuthor();
		vAuthor.push_back(B.Author); //вектор со всеми АВТОРАМИ
		B.SetName();
		vName.push_back(B.Name); //вектор со всеми НАЗВАНИЯМИ
		B.SetYear();
		vYear.push_back(B.Year); //вектор со всеми ГОДАМИ

		cout << "----------" << endl;
	
	}
	int udcw;
	do
	{
		cout << "*Если вы хотите закончить, напишите 0*\nНомер УДК книги, которую Вы хотите взять: ";
		cin >> udcw;

		if (amount[udcw] > 0)
		{
			cout << "Книга в наличии!" << endl;
			cout << "Кол-во экзэмпляров: " << amount[udcw] << endl;
			cout << "Вы взяли книгу!";
			amount[udcw] = amount[udcw] - 1;
			cout << "Теперь кол-во экзэмпляров: " << amount[udcw] << endl;
		}
		else
			cout << "Этой книги нет в наличии!" << endl;

		int back;
		if (udcw != 0)
		{
			cout << "Хотите вернуть книгу? Если да, то 1, нет, до 2: ";
			cin >> back;
			if (back == 1)
			{
				amount[udcw] = amount[udcw] + 1;
				cout << "Теперь кол-во экзэмпляров: " << amount[udcw] << endl;
			}
		}
	} while (udcw != 0);
}
