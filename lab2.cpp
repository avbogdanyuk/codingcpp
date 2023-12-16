#include <iostream>
using namespace std;

class Zoo
{
private:
	string answer;
	int amount;
public:

	void Welcome() //приветствие
	{
		cout << endl << "Животное радо Вас видеть!" << endl;
	}

	void SetAmount(int a) //количество
	{
		amount = a;
	}

	void Print()
	{
		cout << endl << "Всего в зоопарке штук: " << amount << endl;
	}
};

class Parrot : public Zoo //Попугай - количество, окрас, повтор фразы
{
private:
	int answer;
	string phrase;

public:

	void Color() //Цвет
	{
		cout << "Оливково-зеленый окрас";
	}

	void Pet()
	{
		cout << "Вы хотите погладить попугая? Если да, то 1, если нет, то 0: ";
		cin >> answer;
		if (answer == 1)
			cout << endl << "*он кусает Вас и быстро улетает*" << endl << "( o°o)" << endl;
		else
			cout << endl << "Попугай: Крррруто~" << endl;
	}
};

class Golden : public Zoo //Золотая рыбка - КОЛИЧЕСТВО, ВИД, ЖЕЛАНИЕ
{
private:
	int answer;
public:
	
	void Species()
	{
		cout << "Обыкновенная Золотая Рыбка (Common Goldfish)" << endl;
	}

	void Wish() //желание
	{
		cout << "Вы хотите выловить рыбку? Если да, то 1, если нет, то 0: ";
		cin >> answer;
		if (answer == 1)
			cout << endl << "*вылезла из Ваших рук*" << endl << "( o°o)" << endl;
		else
			cout << endl << "Все Ваши желания были исполнены~" << endl;
	}
};

class Mamal: public Zoo
{
private:
	string predator;

public:
	void SetPred(string ynpredator) //хищник да или нет
	{
		predator = ynpredator;
	}

	void GetPred()
	{
		cout << predator;
	}
};

class Lion : public Mamal //ЛЕВ - КОЛИЧЕСТВО, ХИЩНИК, РЫК
{
private:
	int answer;
public:
	void Roar() //рык
	{
		cout << endl << "Вы хотите подойти ближе? Если да, то 1, если нет, то 0: ";
		cin >> answer;
		if (answer == 1)
			cout << endl << "*свирепое хищное рычание*" << endl << "( o°o)" << endl;
		else 
			cout << endl << ":D" << endl;
	}
};

class Monkey : public Mamal // ОБЕЗЯНА - КОЛИЧЕСТВО, ХИЩНИК, ДВИЖЕНИЕ
{
private:
	int answer;
public:
	void Move() //движение
	{
		cout << endl << "Вы хотите подойти ближе? Если да, то 1, если нет, то 0: ";
		cin >> answer;
		if (answer == 1)
			cout << endl << "Минус сумка...(обезьянка, забрала вашу сумку. она действительно ей больше подходит...)" << endl;
		else
			cout << endl << ":(" << endl;
	}
};

void Liion() //Лев
{
	Lion l;
	l.Welcome();
	l.SetPred("Лев - это хищное животное!");
	l.GetPred();
	l.SetAmount(5);
	l.Print();
	l.Roar();
}

void Monkeey() //Обезьяна
{
	Monkey m;
	m.Welcome();
	m.SetPred("Обезьяны являются всеядными, представители большинства видов обезьян питаются преимущественно растительной пищей");
	m.GetPred();
	m.SetAmount(3);
	m.Print();
	m.Move();
}

void Goolden() //Золотая рыбка
{
	Golden g;
	g.Welcome();
	g.Species();
	g.SetAmount(23);
	g.Print();
	g.Wish();
}

void Paarrot() //Попугай
{
	Parrot p;
	p.Welcome();
	p.Color();
	p.SetAmount(33);
	p.Print();
	p.Pet();
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