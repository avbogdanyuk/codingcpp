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
        v[i] = 0;
    }
}

vect::vect(int d, double* x)
{
    
}

vect::vect(vect& x)
{
    count++; //count = count + 1
    num = count;
    cout << "\nКонструктор vect(vect& x) создал вектор N " << num << endl;
    dim = x.dim; //razmernost' odinakova teper'
    v = new double[dim]; //vidilyaem pamyat' pod massive sostoyashoy iz dim amount of double elements
    for (int i = 0; i < dim; i++)
    {
        v[i] = x.v[i]; //copying elements step by step
    }
}

void vect::print()
{
    cout << "Размерность " << dim << endl;
    cout << "Адрес вектора " << v << endl;
    cout << "Номер вектора " << num << endl;
    
    if (dim == 0) cout << "No elements";
    
    for (int i=0; i<dim; i++)
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
    return *this;
}

vect vect::operator+(vect& r)
{
    
}

int main()
{
    vect v(3);
    v.print();
    
    vect l(v);
    l.print();
    
}
