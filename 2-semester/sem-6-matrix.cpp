#include <iostream>
using namespace std;

class matr //kvadratnaya matrix
{
    int dim; //razmernost'
    double* a; //components
    public:
    
    //constuctors
    matr(); //null matrix, a=NULL
    matr(matr& x); //copying
    matr(int n); //edinichnaya matrix
    matr(int n, double* x); //dannie dlya component matrix iz x
    
    //destructor
    ~matr()
    {
        delete a;
    }
    
    //methods
    void print();
    matr operator+(matr& r);
    matr operator-(matr& r);
    matr operator-();
    matr operator*(matr& r); //matrix umnozhaetsya na matrix
    friend matr operator*(double k, matr& r);
    //vect operator*(vect& r); //umnozhenie matrix na vector
};

int index(int n, int i, int j)
{
    return n*(i-1)+j-1;
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
    for (int i=1; i<=dim; i++)
    for (int j=1; j<=dim; j++)
    {
        a[index(dim, i, j)] = 1;
    }
}

matr::matr(matr& x)
{
    matr tmp;
    tmp.dim = x.dim;
    tmp.a = new double[dim];
    for (int i=1; i<=dim; i++)
    for (int j=1; j<=dim; j++)
    {
        tmp.a[index(dim, i, j)] = x.a[index(dim, i, j)];
    }
}

void matr::print()
{
    for (int i=1; i<=dim; i++)
    for (int j=1; j<=dim; j++)
    {
        cout << a[index(dim, i, j)];
    }
}

matr matr::operator*(matr& r)
{
    matr tmp(this->dim); //prosto berem razmernost' left operand, po prikolu
    
    for (int i=1; i<=dim; i++)
    for (int j=1; j<=dim; j++)
    {
        tmp.a[index(dim, i, j)] = 0;
        for (int k=1; k<=dim; k++)
        {
            tmp.a[index(dim, i, j)] += a[index(dim, i, k)]*r.a[index(dim, k, j)];
        }
    }
    return tmp;
}

int main()
{
    matr m1(3);
    m1.print();
}
