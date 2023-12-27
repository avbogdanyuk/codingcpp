#include <iostream>
using namespace std;

class Zoo
{
public:
string name;
int weight;

virtual void  Eat()
{
 cout << name << "is eating" << endl;
}
virtual void Noise()
{
	cout << name<< "is making noise" << endl;
}
virtual void Weight()
{
	cout << name << "'s weight is" << weight;
}
virtual void Pet()
{
	cout <<"you are petting" << name <<"right now" <<endl;
}
};

class Parrot : public Zoo //Попугай - количество, окрас, повтор фразы
{
public:
string color;
virtual void Color()
{
	cout << name << "is" << color<<endl;
}
};

class Golden : public Zoo //Золотая рыбка - КОЛИЧЕСТВО, ВИД, ЖЕЛАНИЕ
{
public:
string shape;
virtual void Shape()
{
	cout << name << "is" << shape<<endl;
}
};

class Mamal: public Zoo
{
public:
bool Danger;
virtual void IsDanger()
{
	cout << "Is dangerous" << Danger << endl;
}
};

class Lion : public Mamal //ЛЕВ - КОЛИЧЕСТВО, ХИЩНИК, РЫК
{
public:
 virtual void Roar()
{
 cout << name << "is roaring" << endl;
}
};

class Monkey : public Mamal // ОБЕЗЯНА - КОЛИЧЕСТВО, ХИЩНИК, ДВИЖЕНИЕ
{
public:
virtual void Steal()
{
	cout << name << "stole your purse!"<<endl;
}
};

void Liion() //Лев
{
	Lion l;
	l.name = "Lion";
	l.Eat();
	l.Noise();
	l.weight = 120;
	l.Weight();
	l.Pet();
	l.Danger = true;
	l.IsDanger();
	l.Roar();
}

void Monkeey() //Обезьяна
{
	Monkey m;
	m.name = "Monkey";
	m.Eat();
	m.Noise();
	m.weight = 60;
	m.Weight();
	m.Pet();
	m.Danger = false;
	m.IsDanger();
	m.Steal();
}

void Goolden() //Золотая рыбка
{
	Golden g;
	g.name = "Golden Fish";
	g.Eat();
	g.Noise();
	g.weight = 1;
	g.Weight();
	g.Pet();
	g.shape = "small";
	g.Shape();
}

void Paarrot() //Попугай
{
	Parrot p;
	p.name = "Parrot";
	p.Eat();
	p.Noise();
	p.weight = 5;
	p.Weight();
	p.Pet();
	p.color = "bright blue";
	p.Color();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int wants;
	cout << "Добро пожаловать, дорогой посетитель, в наш невероятный зоопарк" << endl;

	do {
		cout << endl << "К какому животному вы хотите подойти?" << endl << "1)Лев, 2)Обезьяна, 3)Золотая рыбка, 4)Попугай или 5)СТОП" << endl;
		cin >> wants;

		if (wants == 1) {
			Liion();
		}
		else if (wants == 2) {
			Monkeey();
		}
		else if (wants == 3) {
			Goolden();
		}
		else if (wants == 4) {
			Paarrot();
		}

	} while (wants != 5);
}
