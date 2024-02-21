#include <iostream>
#include <string>
using namespace std;

struct tovar
{
    string name;
    float price;
    int amount;
    tovar* next;
};

void addfirst(tovar* &tlist, string n, float p, int am)
{ //чтобы изменения сохранялись ВНЕ этой функции, нужно использовать ссылку
    tovar* tmp = new tovar;
    
    tmp -> name = n;
    tmp -> price = p;
    tmp -> amount = am;
    
    tmp -> next = tlist;
    tlist = tmp;
    return;
}

//добавить товар в список после заданного
int addafter(tovar* bufet, string n, float p, int am,string nafter)
{   //последнее -- это имя товара, после которого мы хотим сделать добавление
    //буфет - это список, в начале он является первым элементом списка
    
    tovar* newtovar = new tovar;
    
    
    
    //проверяем,что список не пустой
    if (bufet == NULL) return 1;
    
    tovar* tmp = bufet; //описание с инициализацией
    while (tmp != NULL && tmp -> name != nafter)
    {
        tmp = tmp -> next;
        if (tmp == NULL) return 1;
    }
    
    newtovar -> name = n;
    newtovar -> price = p;
    newtovar -> amount = am;
    
    newtovar -> next = tmp -> next;
    tmp -> next = newtovar;
    return 0;
}

int main()
{
    
}
