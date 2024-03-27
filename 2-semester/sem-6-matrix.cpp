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
    vect operator*(vect& r); //umnozhenie matrix na vector
};

matr matr::operator*(matr& r)
{
    matr tmp(this->dim); //prosto berem razmernost' left operand, po prikolu
    
    for (int i=1; i<=dim; i++)
    for (int j=1; j<=dim; j++)
    {
        tmp.a[ind(dim, i, j)] = 0;
        for (int k=1; k<=dim; k++)
        {
            tmp.a[ind(dim, i, j)] += a[ind(dim, i, k)]*r.a[ind(dim, k, j)]
        }
    }
}
