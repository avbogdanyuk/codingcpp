#include <iostream>
#include <string>
using namespace std;

struct tovar
{
	string name;
	double price;
	int amount;
	tovar* next; //ссылка на след.узел
};

tovar* CreateTovar(string n, float p, int am) //создание эдемента списка
{
	tovar* NewTovar = new tovar; //указатель на новый узел

	NewTovar->name = n; //записываем имя, цену, кол-во нового товара
	NewTovar->name = p;
	NewTovar->name = am;
	NewTovar->next = NULL; //следующего узла нет

	return NewTovar; //результат функции - адрес узла
}
//далее требуется добавить узел к списку (с начало, в конец, или в середину)

void AddFirst(tovar* &head, tovar* NewTovar)
{
	NewTovar->next = head; //устанавливаем ссылку узла NewTovar на голову
	head = NewTovar; //NewTovar теперь новая голова списка
}

void AddAfter(tovar* afterit, tovar* NewTovar) //добавление узла после заданного (afterit)
{
	NewTovar->next = afterit->next; //устанавливаем ссылку нового узла на узел, следующий за данным
	afterit->next = NewTovar; //устанавливаем ссылку данного узла afterit на NewTovar
}

void AddBefore(tovar* head, tovar* beforeit, tovar* NewTovar) //добавление узла перед заданным
{
	tovar* tmp = head;

	if (head == beforeit) //если тот узел, перед которым мы хотим добавить узел
						//является головой списка, то используем функций AddFirst
	{
		AddFirst(head, NewTovar);
		return;
	}

	while (tmp && tmp->next != beforeit) //ищем узел, за которым следует beforeit
		tmp = tmp->next;
	if (tmp) //если нашелсся такой узел, добавляем после него новый узел
		AddAfter(tmp, NewTovar);
}

void AddLast(tovar*& head, tovar* NewTovar)
{
	tovar* tmp;

	tmp = head;

	while (tmp != NULL)
	{
		tmp = tmp->next;

		if (tmp->next = NULL);
		AddAfter(tmp, NewTovar);
	}
}

int main()
{
	tovar *tmp, *head;
	head = NULL;

	for (int i = 3; i > 0; i--) //создаем список
	{
		tmp = new tovar;

		cout << "Enter the name of new item: " << endl;
		cin >> tmp-> name;
		cout << "Enter the price of new item: " << endl;
		cin >> tmp->price;
		cout << "Enter the amount of new item: " << endl;
		cin >> tmp->amount;
		cout << "\n";

		tmp->next = head;

		head = tmp;
	}

	while (tmp != NULL) //вывод списка c начала
	{
		cout << tmp->name << endl;
		cout << tmp->price << endl;
		cout << tmp->amount << endl << "\n";
		tmp = tmp->next;
	}
}
