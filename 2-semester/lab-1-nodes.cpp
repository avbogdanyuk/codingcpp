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

int AddAfter(tovar* tlist, string nameafter, string n, double p, int am) //добавление узла после заданного
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

	NewTovar->next = tmp->next; 
	tmp->next = NewTovar;

	return 0;
}

void AddBefore(tovar* tlist, string namebefore, string n, double p, int am) //добавление узла перед заданным
{
	tovar* tmp = tlist;

	if (tmp->name == namebefore) //если тот узел, перед которым мы хотим добавить узел
		//является головой списка, то используем функций AddFirst
	{
		AddFirst(tmp, n, p, am);
		return;
	}

	while (tmp != NULL && tmp->name != namebefore)
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
		if (tmp->next = NULL)
		{
			AddAfter(tlist, tmp->name, n, p, am);
			return;
		}
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

int DeleteTovar(tovar* &tlist, string namedelete) //удаление узла
{
	if (tlist == NULL) return 1; //если список пустой, то и удалять нечего

	tovar* tmp = tlist;

	if (tmp->name == namedelete)//если требуется удалить голову
	{
		tlist = tmp->next;
		delete tmp;
		return 0;
	}

	while (tmp->next!= NULL && tmp->name != namedelete) //если нужно удалить не голову
	{
		tmp = tmp->next;
		tmp->next = tmp->next->next;
	}

	return 0;
}

int main()
{
	tovar* tmp, * head;
	head = NULL;
	int option = 0;

	while (option != 8)
	{
		cout << "Choose option: \n 1)Create list or add new element in beginning\n2)Add first\n3)Add after\n4)Add before\n5)Add last\n6)Delete element\n7)Print list\n8)End\n";
		cin >> option;

		if (option == 1) //create list или добавляем элементы в начало списка.Дополняем существующий
		{
			int number;

			cout << "How many element do you want to add?";
			cin >> number;

			for (number; number > 0; number--) //создаем список
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
		}

		if (option == 2) //add first
		{
			string n;
			double p;
			int am;

			cout << "Enter the name of new item: " << endl;
			cin >> n;
			cout << "Enter the price of new item: " << endl;
			cin >> p;
			cout << "Enter the amount of new item: " << endl;
			cin >> am;
			cout << "\n";

			AddFirst(head, n, p, am);
		}

		if (option == 3) //add after
		{
			string n;
			double p;
			int am;
			string nafter;

			cout << "Enter the name of new item: " << endl;
			cin >> n;
			cout << "Enter the price of new item: " << endl;
			cin >> p;
			cout << "Enter the amount of new item: " << endl;
			cin >> am;
			cout << "\n";

			cout << "After what element's NAME do you want to add?";
			cin >> nafter;

			AddAfter(head, nafter, n, p, am);
		}

		if (option == 4) //add before
		{
			string n;
			double p;
			int am;
			string nbefore;

			cout << "Enter the name of new item: " << endl;
			cin >> n;
			cout << "Enter the price of new item: " << endl;
			cin >> p;
			cout << "Enter the amount of new item: " << endl;
			cin >> am;
			cout << "\n";

			cout << "Before what element's NAME do you want to add?";
			cin >> nbefore;

			AddBefore(head, nbefore, n, p, am);
		}

		if (option == 5) //add last
		{
			string n;
			double p;
			int am;

			cout << "Enter the name of new item: " << endl;
			cin >> n;
			cout << "Enter the price of new item: " << endl;
			cin >> p;
			cout << "Enter the amount of new item: " << endl;
			cin >> am;
			cout << "\n";

			AddLast(head, n, p, am);
		}

		if (option == 6) //delete
		{
			string n;

			cout << "Enter the name of item you want to delete: " << endl;
			cin >> n;
			cout << "\n";

			DeleteTovar(head, n);
		}

		if (option == 7) //print list
		{
			PrintList(head);
		}
	}

	PrintList(head);
}
