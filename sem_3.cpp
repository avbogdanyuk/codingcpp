#include <iostream>
#include <string>
using namespace std;

struct tovar
{
    string name;
    float price;
    int amount;
    tovar* next;
}

void addfirst(tovar* &tlist, string n, float p, int am) //effect elements out off function
{
    tovar* tmp = new tovar;
    tmp -> name = n;
    tmp -> price = p;
    tmp -> amount = am;
    tmp -> next = tlist;
    tlist = tmp;
    return;
}

int main()
{
    
}
