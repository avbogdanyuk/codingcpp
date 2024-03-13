//x=a+ib comlex numbers, a - действительная re, b -мнимая im

#include <iostream>
using namespace std;

class complex
{
    public:
    double re; double im; //polya
    
    complex() //methods, конструктор, поэтому название просто название класса. Если (), то функция.
    {
        re = 0;
        im = 0;
    }
    
    complex(double r, double i)//конструктор, задаем новое значение re, im
    {
        re = r;
        im = i;
    }
    
    complex(complex &x); //задача этого конструктора создать копию, полное определение будет ВНЕ класса
    
    ~complex(){};//диструктор
    
    void set(double, double);//установление значения комплексного числа(double r, double i)
    
    void print(); //вывод комп.числа
    
    //оператор функции
    //компонентная функция класса
    complex operator+(complex &right);//правый операнд
};

complex::complex(complex &x) //это адрес, но используем как переменную. копируем значения действ.и мнимой частей из компл.числа х
{
    re = x.re;
    im = x.im;
}

void complex::set(double r, double i) //присваиваем новые значения
{
    re = r;
    im = i;
}

void complex::print()
{
    cout << "real = " << re << "\nimaginary = " << im << endl; //it prints, for sure
}

complex complex::operator+(complex &right) //то же, что и разность, только сумма
{
    complex tmp;
    tmp.re = re + right.re;
    tmp.im = im + right.im;
    return tmp;
}

complex operator-(complex l, complex r) //внешняя функция, для вычисления разности
{
    complex tmp;
    tmp.re = l.re - r.re; //разность действительных частей
    tmp.im = l.re - r.re; //разность мнимых частей
    return tmp;
}

int main()
{
    complex c;
    
    c.print();
    c.set(1,1);
    c.print();
    
}
