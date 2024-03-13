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
    
    //constractions
    vect();
    vect(int d); //d - razmernost vectora, nulevoy vector
    vect(int d, double* x); //x contains component of vector
    vect(vect &x); //constactor of copying\
    
    //distractor
    ~vect();
    
    //basic... methods of the class
    void print();
    vect &operator+(vect &right); //component function of class, left opertor is known...i suppose
    //make a function a friend of class
    friend vect operator-(vect l, vect r);
    vect &operator=(const vect &r);
};
