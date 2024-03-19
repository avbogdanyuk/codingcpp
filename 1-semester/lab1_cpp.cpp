#include <iostream>

using namespace std;

int sum(int x, int y)
{
	cout << x + y;
	return 0;
}

int subt(int x, int y)
{
	cout << x + y;
	return 0;
}

int mult(int x, int y)
{
	cout << x * y;
	return 0;
}

float divi(int x, int y)
{
	if (y != 0)
		cout << x * 1.0 / y * 1.0;
	else
		cout << "ERROR";
	return 0;
}

int power(int x, int y)
{
	cout << pow(x, y);
	return 0;
}

float root(int x, int y)
{
	if (x < 0 and y % 2 == 0)
		cout << "ERROR";
	else
		cout << pow(x*1.0, 1.0/y*1.0);
	return 0;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	int x; int y; 
	string operation;

	cout << "Первый целый элемент = ";
	cin >> x;
	cout << "Доступные операции\n+ - * / ^ root\n";
	cin >> operation;
	cout << "Второй целый элемент = ";
	cin >> y;

	if (operation == "+")
		sum(x, y);

	else if (operation == "-")
		subt(x, y);

	else if (operation == "*")
		mult(x, y);

	else if (operation == "/")
		divi(x, y);

	else if (operation == "^")
		power(x, y);

	else if (operation == "root")
		root(x, y);
}
