//x=a+ib comlex numbers, a - действительная re, b -мнимая im

#include <iostream>

class Complex
{
    public:
    double re; double im;
    
    complex() //конструктор, поэтому название просто название класса. Если (), то функция.
    {
        re = 0;
        im = 0;
    }
    
    complex(double r, double i)//конструктор, задаем новое значение re, im
    {
        re = r;
        im = i;
    }
    
    comlex(comlex &x); //задача этого конструктора создать копию, полное определение будет ВНЕ класса
    
    ~complex(){};//диструктор
    
    void set(double, double);//установление значения комплексного числа(double x, double y)
    
    void print(); //вывод комп.числа
    
    //оператор функции
    //компонентная функция класса
    complex operator+(complex &right);//правый операнд
};

complex::complex()//определяем конструктор, функция комплекс из класса комплекс
{
    re = r;
    im = i;
}

complex::complex(complex &x) //это адрес, но используем как переменную
{
    re = x.re;
    im = x.im
}

void complex::set(double r, double i)
{
    re = r;
    im = i;
}

void print()
{
    
}

complex complex::operator+(complex &right)
{
    
}
