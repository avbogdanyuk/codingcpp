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
    cout << endl << "real = " << re << "\nimaginary = " << im << endl; //it prints, for sure
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
    tmp.im = l.im - r.im; //разность мнимых частей
    return tmp;
}

int main()
{
    complex aa = complex(); //using contsructor. inizialization
    cout << aa.re << endl << aa.im << endl;
    
    aa.set(232,1);
    aa.print();
    
    complex second = complex(1, 2.1);
    second.print();
    
    //second = complex(aa); //copying
    //second.print();
    
    complex c3 = aa - second; //minus
    c3.print();
    
    complex c4 = aa + second;
    c4.print();
}
