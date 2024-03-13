#include <iostream>
using namespace std;

class vect
{
    int dim; //razmernost vectora
    double* v; //components of class, massive that containt amount of components
    int num; //nomer vectora
    
    public:
    static int count; //amount of created vectors
    
    //methods
    
    //constractors
    vect();
    vect(int d); //d - razmernost vectora, nulevoy vector
    vect(int d, double* x); //x contains component of vector
    vect(vect &x); //constactor of copying
    
    //distractor
    ~vect();
    
    //basic... methods of the class
    void print();
    vect &operator+(vect &right); //component function of class, left opertor is known...i suppose
    //make a function a friend of class
    friend vect operator-(vect l, vect r);
    vect &operator=(const vect &r);
};

int vect::count = 0; //necessary!!!

vect::vect(int d)
{
    count++; //count = count + 1
    num = count;
    cout << "Konstruktor vect(int d) sozdal vector N" << num;
    dim = d;
    v = new double[dim];
    for (int i=0; i<dim; i++)
    {
        v[i] = 0;
    }
}

vect::vect(vect &x)
{
    count++; //count = count + 1
    num = count;
    cout << "Konstruktor vect(int d) sozdal vector N" << num;
    dim = x.dim;
    v = new double[dim];
    for (int i=0; i<dim; i++)
    {
        v[i] = x.v[i];
    }
}

vect &vect::operator=(const vect &r)
{
    if (dim == 0)
    {
        dim = r.dim;
        v = new double[dim];
    }
    for (int i=0; i<dim; i++)
    {
        v[i] = r.v[i];
    }
    return *this;
}
