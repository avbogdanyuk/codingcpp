#include <iostream>
#include <string>
using namespace std;

struct tovar
{
	string name;
	float price;
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

void AddFirst(tovar* &bufet, tovar* NewTovar)
{
	NewTovar->next = bufet; //устанавливаем ссылку узла NewTovar на голову
	bufet = NewTovar; //NewTovar теперь новая голова списка
}

void AddAfter(tovar* afterit, tovar* NewTovar) //добавление узла после заданного (afterit)
{
	NewTovar->next = afterit->next; //устанавливаем ссылку нового узла на узел, следующий за данным
	afterit->next = NewTovar; //устанавливаем ссылку данного узла afterit на NewTovar
}

void AddBefore(tovar* bufet, tovar* beforeit, tovar* NewTovar) //добавление узла перед заданным
{
	tovar* tmp = bufet;

	if (bufet == beforeit) //если тот узел, перед которым мы хотим добавить узел
						//является головой списка, то используем функций AddFirst
	{
		AddFirst(bufet, NewTovar);
		return;
	}

	while (tmp && tmp->next != beforeit) //ищем узел, за которым следует beforeit
		tmp = tmp->next;
	if (tmp) //если нашелсся такой узел, добавляем после него новый узел
		AddAfter(tmp, NewTovar);
}


int main()
{
	
}
