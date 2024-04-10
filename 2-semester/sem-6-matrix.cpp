#include <iostream>
using namespace std;

class matr //квадратная матрица
{
    int dim; //размерность
    double* a; //компененты
public:

    //constuctors
    matr(); //null matrix, a=NULL
    matr(matr& x); //копирование
    matr(int n); //единичная матрица
    matr(int n, double* x); //данные для компонент матрицы из x

    //destructor
    ~matr() { delete a; };

    //methods
    void print();
    matr operator+(matr& r);
    //matr operator-(matr& r);
    //matr operator-();
    matr operator*(matr& r); //матрица умножается на матрицу
    //friend matr operator*(double k, matr& r);
    //vect operator*(vect& r); //умножение матрицы на вектор
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
    a = new double[dim];
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            a[index(dim, i, j)] = 0;

            if (index(dim, i, j)%(dim+1) == 0) a[index(dim, i, j)] = 1;
        }
}

matr::matr(matr& x)
{
    matr tmp;
    tmp.dim = x.dim;
    tmp.a = new double[dim];
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            tmp.a[index(dim, i, j)] = x.a[index(dim, i, j)];
        }
}

matr::matr(int n, double* x)
{
    dim = n;
    a = new double[n];
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
}


matr matr::operator*(matr& r)
{
    matr tmp(this->dim); //берем размерность левого операнда

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
        {
            tmp.a[index(dim, i, j)] = 0;
            for (int k = 1; k <= dim; k++)
            {
                tmp.a[index(dim, i, j)] += a[index(dim, i, k)] * r.a[index(dim, k, j)];
            }
        }
    return tmp;
}

int main()
{
    matr m1(2);
    m1.print();
}
