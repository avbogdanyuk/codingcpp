#include <iostream>
using namespace std;

class vect
{
    int dim; //размерность вектора
    double* v; //компоненты класса, массив содержит количество компонентов, pointer
    int num; //номер вектора

public:
    static int count; //количество созданных векторов

    //Методы

    //конструкторы
    vect();
    vect(int d); //d - размерность векторы, нулевой вектор
    vect(int d, double* x); //x содержит компоненты вектора
    vect(vect& x); //конструктор копирования

    //диструктор
    ~vect(){};

    //обычные методы класса
    void print();
    vect operator+(vect& r); //компонентная функция класса, левый операнд известен
    //создаем функцию ДРУГ КЛАССА
    //friend vect operator-(vect l, vect r);
    vect operator=(const vect& r);
};

int vect::count = 0; //НЕОБХОДИМО!

vect::vect()
{
    num = 0;
    dim = 0;
    v = new double[dim];
    num = 0;
    cout << "Конструктор vect() создал вектор N " << num;
}

vect::vect(int d)
{
    count++; //count = count + 1
    num = count;
    cout << "Конструктор vect(int d) создал вектор N " << num;
    dim = d;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = 0;
    }
}

vect::vect(int d, double* x)
{
    count++;
    num = count;
    cout << "Конструктор vect(int d, double* x) создал вектор N " << num;
    dim = d;
    v = x;
    for (int i = 0; i < dim; i++)
    {
        v[i] = 0;
    }
}

vect::vect(vect& x)
{
    count++; //count = count + 1
    num = count;
    cout << "Конструктор vect(vect& x) создал вектор N " << num;
    dim = x.dim; //razmernost' odinakova teper'
    v = new double[dim]; //vidilyaem pamyat' pod massive sostoyashoy iz dim amount of double elements
    for (int i = 0; i < dim; i++)
    {
        v[i] = x.v[i]; //copying elements step by step
    }
}

void vect::print()
{
    cout << dim;
    cout << v;
    cout << num;
}

vect vect::operator=(const vect& r)
{
    if (dim == 0)
    {
        dim = r.dim;
        v = new double[dim];
    }
    for (int i = 0; i < dim; i++)
    {
        v[i] = r.v[i];
    }
    return *this;
}

vect vect::operator+(vect& r)
{
    if (dim != r.dim) //если кол-во элементов в левом векторе не равно кол-ву эл. в правом, то мы не можем продолжать(
    {
        count++;
        num=count;
        v = new double[dim];
        for (int i=0; i<dim; i++)
        {
            v[i] = v[i] + r.v[i];   
        }
    }
    return 0;
}

int main()
{
    vect v;

}
