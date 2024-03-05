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

void AddFirst(tovar*& tlist, string n, double p, int am)
{
	tovar* NewTovar = new tovar; //указатель на новый узел

	NewTovar->name = n; //записываем имя, цену, кол-во нового товара
	NewTovar->price = p;
	NewTovar->amount = am;
	NewTovar->next = NULL; //следующего узла нет

	NewTovar->next = tlist; //устанавливаем ссылку узла NewTovar на голову
	tlist = NewTovar; //NewTovar теперь новая голова списка

	return;
}

int AddAfter(tovar* tlist, string nameafter, string n, double p, int am) //добавление узла после заданного (afterit)
{
	tovar* NewTovar = new tovar; //указатель на новый узел

	NewTovar->name = n; //записываем имя, цену, кол-во нового товара
	NewTovar->price = p;
	NewTovar->amount = am;
	NewTovar->next = NULL; //следующего узла нет

	tovar* tmp = tlist;

	while (tmp != NULL && tmp->name != nameafter)
	{
		if (tmp->name == nameafter) return 1;
		tmp = tmp->next;
	}

	NewTovar->next = tmp->next; //устанавливаем ссылку нового узла на узел, следующий за данным
	tmp->next = NewTovar; //устанавливаем ссылку данного узла afterit на NewTovar

	return 0;
}

void AddBefore(tovar* tlist, string namebefore, string n, double p, int am) //добавление узла перед заданным
{
	tovar* tmp = tlist;

	if (tmp->name == namebefore) //если тот узел, перед которым мы хотим добавить узел
		//является головой списка, то используем функций AddFirst
	{
		AddFirst(tmp, n, p, am); //ПОЧЕМУ НЕ РАБОТАЕТ????
		return;
	}

	while (tmp != NULL && tmp->name != namebefore) //ищем узел, за которым следует beforeit
	{
		if (tmp->next->name == namebefore) //если нашелсся такой узел, добавляем после него новый узел
			AddAfter(tlist, tmp->name, n, p, am);
		tmp = tmp->next;
		return;
	}
}

void AddLast(tovar* tlist, string n, double p, int am)
{
	tovar* tmp = tlist;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		if (tmp->next = NULL);
			AddAfter(tlist, tmp->name, n, p, am);
			return;
	}
}

void PrintList(tovar* tlist)
{
	while (tlist != NULL) //вывод списка c начала
	{
		cout << tlist->name << endl;
		cout << tlist->price << endl;
		cout << tlist->amount << endl << "\n";
		tlist = tlist->next;
	}
}

int DeleteTovar(tovar* tlist, string namedelete)
{
	tovar* tmp = tlist;

	if (tmp->name == namedelete)//если это первый элемент, АЭТОНЕТ!!!
	{
		tmp = tmp->next;
		return 1;
	}

	while (tmp != NULL && tmp->name != namedelete) //это работает!
	{
		if (tmp->next->name == namedelete)
		{
			tmp->next = tmp->next->next;
			return 1;
		}
	}
}

int main()
{
	tovar* tmp, * head;
	head = NULL;

	for (int i = 2; i > 0; i--) //создаем список
	{
		tmp = new tovar;

		cout << "Enter the name of new item: " << endl;
		cin >> tmp->name;
		cout << "Enter the price of new item: " << endl;
		cin >> tmp->price;
		cout << "Enter the amount of new item: " << endl;
		cin >> tmp->amount;
		cout << "\n";

		tmp->next = head;

		head = tmp;
	}

	DeleteTovar(tmp, "poop");

	PrintList(tmp);
}
