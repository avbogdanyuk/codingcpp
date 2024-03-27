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
    //vect(int d, double* x); //x содержит компоненты вектора
    vect(vect& x); //конструктор копирования

    //диструктор
    ~vect() {};

    //обычные методы класса
    void print();
    vect operator+(vect& r); //компонентная функция класса, левый операнд известен
    //создаем функцию ДРУГ КЛАССА
    friend vect operator-(vect l, vect r);
    vect operator=(const vect& r);
    vect operator-();//uno uno
    double operator*(vect& r); //скалярное произведение
    friend vect operator*(double k, vect& r);
};

int vect::count = 0; //НЕОБХОДИМО!

vect::vect()
{
    count++;
    num = count;
    dim = 0;
    v = new double[dim];
    cout << "\nКонструктор vect() создал вектор N " << num << endl;
}

vect::vect(int d)
{
    count++; //count = count + 1
    num = count;
    cout << "\nКонструктор vect(int d) создал вектор N " << num << endl;
    dim = d;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = 1;
    }
}

vect::vect(vect& x)
{
    count++; //count = count + 1
    num = count;
    cout << "\nКонструктор vect(vect& x) копирования " << num << endl;
    dim = x.dim; //размерность теперь одинаковая
    v = new double[dim]; //выделяем память под массив, состоящий из dim кол-ва double элементов
    for (int i = 0; i < dim; i++)
    {
        v[i] = x.v[i]; //copying elements step by step
    }
}

void vect::print()
{
    cout << "\nВывод вектора на экран" << endl;
    if (dim == 0) cout << "No elements";

    for (int i = 0; i < dim; i++)
    {
        cout << v[i];
    }
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
    cout << "\nПрисваивание значений вектору N " << num << endl;

    return *this;
}

vect vect::operator+(vect& r)
{
    cout << "\nСоздаем новый вектор N " << num << endl;
    vect tmp(dim);
    for (int i = 0; i < dim; i++)
    {
        tmp.v[i] = v[i] + r.v[i];
    }
    return tmp;
}

vect operator-(vect l, vect r)
{
    cout << "\nОператор вычитания" << endl;
    vect tmp(l.dim);
    for (int i = 0; i < l.dim; i++)
    {
        tmp.v[i] = l.v[i] - r.v[i];
    }
    return tmp;
}

vect vect::operator-()
{
    cout << "\nОператор унарного вычитания" << endl;
    for (int i = 0; i < dim; i++)
    {
        v[i] = -v[i];
    }
    return *this;
}

double vect::operator*(vect& r)//скалярное произведение
{
    double dotprod = 0;
    
    cout << "\nОператор вычисления скалярного произведения" << endl;
    
    if (dim == r.dim)
    {
        for (int i=0; i<dim; i++)
        {
            dotprod += v[i]*r.v[i];
        }
    }
    return dotprod;
}

vect operator*(double k, vect& r)
{
    cout << "\nОператор умножения на константу" << endl;
    for (int i=0; i<r.dim; i++)
    {
        r.v[i] = k*r.v[i];
    }
    return r;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    vect l(3); //vect(int d)
    l.print();

    vect r = l; //копирование
    r.print();

    vect sum = r+l;
    sum.print();

    vect diff = r-l;
    diff.print();
    
    (-sum).print();
    
    cout << endl << l*sum;
    
    (4*sum).print();
}
