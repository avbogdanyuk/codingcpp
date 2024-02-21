#include <iostream>
#include <string>
using namespace std;

struct student
{
	long id;
	string name;
	string group;
	student* next;
};

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
