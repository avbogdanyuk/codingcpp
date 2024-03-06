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
    
    void set(double x, double y)//установление значения комплексного числа
    
    void print(); //вывод комп.числа
    
    //оператор функции
    //компонентная функция класса
    
}
