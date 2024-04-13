#include <iostream>
using namespace std;

class vect
{
public:
    int dim; //размерность вектора
    double* v; //компоненты класса
    int num; //номер вектора


    static int count; //количество созданных векторов

    //конструкторы
    vect();
    vect(int d); //d - размерность векторы, нулевой вектор
    vect(int d, double* x); //x содержит компоненты вектора
    vect(vect& x); //конструктор копирования

    //диструктор
    ~vect()
    {
        cout << "\nДиструктор уничтожает вектор N " << num << endl;
        delete v;
    };

    //методы класса
    void print();
    vect operator+(vect& r); //компонентная функция класса, левый операнд известен
    //создаем функцию ДРУГ КЛАССА
    friend vect operator-(vect l, vect r);
    vect operator=(const vect& r);
    vect operator-();//унарное вычитание
    double operator*(vect& r); //скалярное произведение
    friend vect operator*(double k, vect& r);

    friend vect operator*(vect& r);
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

vect::vect(int d, double* x)
{
    count++; //count = count + 1
    num = count;
    cout << "\nКонструктор vect(int d, double* x) создал вектор N " << num << endl;
    dim = d;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = x[i];
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
        v[i] = x.v[i]; //копируем элементы
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

    if (dim > r.dim)
    {
        dim = r.dim;
    }

    for (int i = 0; i < dim; i++)
    {
        v[i] = r.v[i];
    }
    cout << "\nПрисваивание значений вектору N " << num << " значения вектора N " << r.num << endl;

    return *this;
}

vect vect::operator+(vect& r)
{
    cout << "\nСложения вектора N " << num << " и вектора N " << r.num << endl;
    vect tmp(dim);
    for (int i = 0; i < dim; i++)
    {
        tmp.v[i] = v[i] + r.v[i];
    }
    return tmp;
}

vect operator-(vect l, vect r)
{
    cout << "\nВычитание из вектора N "<< l.num << " вектора N "<< r.num << endl;
    vect tmp(l.dim);
    for (int i = 0; i < l.dim; i++)
    {
        tmp.v[i] = l.v[i] - r.v[i];
    }
    return tmp;
}

vect vect::operator-()
{
    cout << "\nЭлементы вектора N " << num << "умноженые на (-1)" << endl;
    for (int i = 0; i < dim; i++)
    {
        v[i] = -v[i];
    }
    return *this;
}

double vect::operator*(vect& r)//скалярное произведение
{
    double dotprod = 0;

    cout << "\nОператор вычисления скалярного произведения вектора N " << num << " и вектора N" << r.num << endl;

    if (dim < r.dim)
        r.dim = dim;
    else
        dim = r.dim;

    for (int i = 0; i < dim; i++)
        {
            dotprod += v[i] * r.v[i];
        }
    return dotprod;
}

vect operator*(double k, vect& r)
{
    cout << "\nОператор умножения на константу" << endl;
    for (int i = 0; i < r.dim; i++)
    {
        r.v[i] = k * r.v[i];
    }
    return r;
}

class matr //квадратная матрица
{
    int dim; //размерность
    double* a; //компененты
public:

    //конструкторы
    matr(); //null matrix, a=NULL
    matr(matr& x); //копирование
    matr(int n); //единичная матрица
    matr(int n, double* x); //данные для компонент матрицы из x

    //диструктор
    ~matr() { delete a; };

    //методы
    void print();
    matr operator+(matr& r);
    matr operator-(matr& r);
    matr operator=(matr& r);
    matr operator-();
    matr operator*(matr& r); //матрица умножается на матрицу
    friend matr operator*(double k, matr& r);
    vect operator*(vect& r); //умножение матрицы на вектор
};

int index(int n, int i, int j)
{
    return n * (i - 1) + j - 1;
}

matr::matr()
{
    dim = 0;
    a = NULL;
}

matr::matr(int n)
{
    dim = n;
    a = new double[dim * dim];
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            a[index(dim, i, j)] = 0;

            if (index(dim, i, j) % (dim + 1) == 0) a[index(dim, i, j)] = 1;
        }
}

matr::matr(matr& x)
{
    dim = x.dim;
    a = new double[dim * dim];
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            a[index(dim, i, j)] = x.a[index(dim, i, j)];
        }
}

matr::matr(int n, double* x)
{
    dim = n;
    a = new double[dim * dim];
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            a[index(dim, i, j)] = x[index(dim, i, j)];
        }
}

void matr::print()
{
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cout << a[index(dim, i, j)];
        }
        cout << endl;
    }
    cout << endl;
}

matr matr::operator-(matr& r)
{
    matr tmp(this->dim); //берем размерность левого операнда

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            for (int k = 1; k <= dim; k++)
            {
                tmp.a[index(dim, i, j)] = a[index(dim, i, k)] - r.a[index(dim, k, j)];
            }
        }
    return tmp;
}

matr matr::operator+(matr& r)
{
    matr tmp(this->dim); //берем размерность левого операнда

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            tmp.a[index(dim, i, j)] = a[index(dim, i, j)] + r.a[index(dim, i, j)];
        }
    return tmp;
}

matr matr::operator=(matr& r)
{
    if (dim == 0)
    {
        dim = r.dim;
        a = new double[dim * dim];
    }

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            a[index(dim, i, j)] = r.a[index(dim, i, j)];
        }

    return *this;
}

matr matr::operator*(matr& r)
{
    matr tmp(this->dim); //берем размерность левого операнда

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            tmp.a[index(dim, i, j)] = a[index(dim, i, j)] * r.a[index(dim, i, j)];
        }
    return tmp;
}

matr matr::operator-()
{
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            a[index(dim, i, j)] = -1 * a[index(dim, i, j)];
        }
    return *this;
}

matr operator*(double k, matr& r)
{
    matr tmp(r.dim); //берем размерность левого операнда

    for (int i = 1; i <= r.dim; i++)
        for (int j = 1; j <= r.dim; j++)
        {
            tmp.a[index(tmp.dim, i, j)] = k * r.a[index(r.dim, i, j)];
        }
    return tmp;
}

vect matr::operator*(vect& r)
{
    vect tmp(dim);
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            tmp.v[i - 1] += a[index(dim, i, j)] * r.v[j - 1];
        }
    }
    return tmp;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    matr m1(2);
    m1.print();

    matr m2;
    m2 = m1;

    matr m3 = m1;

    (9 * m1).print();

    vect vv(2);
    vv.print();

    (m1 * vv).print();

    double mess[4]{ 1,2,3,4 };

    matr mt(2, mess);
    mt.print();
    return 0;
}
