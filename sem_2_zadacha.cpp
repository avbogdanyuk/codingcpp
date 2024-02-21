#include <iostream>
#include <string>
using namespace std;

struct student //структура - это как классы. Общедоступная переменная, типо
{
	long id;
	string name;
	string group;
	student* next; //перед звёздочкой указан ТИП ДАННЫХ (student), а после (next) адрес, указатель
			//Указатели представляют собой объекты, значением которых служат адреса других объектов
			//указатель - это "пустая" переменная (или что-то другое), т.е. у него нет определенного значения, он не ссылается на какой-то опр. объект
};			//int* p{1} - так можно указать конкретный адрес в памяти (в фиг.скобках)
			//int number {25};
			//int *pnumber {&number}; // указатель pnumber хранит адрес переменной number

int main()
{
	setlocale(LC_ALL, "RU");
	
	student *studlist, *tmp;
	studlist = NULL;
	for (int i = 0; i < 3; i++)
	{
		tmp = new student;
		cout << "Ââåäèòå èìÿ:" << endl << i + 1 << ". ";
		cin >> tmp -> name;
		tmp->next = studlist;
		studlist = tmp;
	}
	while (tmp != NULL)
	{
		cout << tmp->name << endl;
		tmp = tmp->next;
	}
}
