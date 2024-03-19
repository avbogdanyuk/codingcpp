#include <iostream>
using namespace std;

class vect
{
    int dim; //размерность вектора
    double* v; //компоненты класса, массив содержит количество компонентов
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
    ~vect();

    //обычные методы класса
    void print();
    vect& operator+(vect& right); //компонентная функция класса, левый операнд известен
    //создаем функцию ДРУГ КЛАССА
    friend vect operator-(vect l, vect r);
    vect& operator=(const vect& r);
};

int vect::count = 0; //НЕОБХОДИМО!

vect::vect(int d)
{
    count++; //count = count + 1
    num = count;
    cout << "Конструктор vect(int d) создал вектор N" << num;
    dim = d;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = 0;
    }
}

vect::vect(vect& x)
{
    count++; //count = count + 1
    num = count;
    cout << "Конструктор vect(int d) создал вектор N" << num;
    dim = x.dim;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = x.v[i];
    }
}

vect& vect::operator=(const vect& r)
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
