#ifndef GROCERYCART_H // guards
#define GROCERYCART_H

#include <string>
#include <list>

using namespace std;

class GroceryCart
{
private:
    list<string> m_produceList;

public:
    GroceryCart(list<string> t_produceList);
    list<string> getRecordsList();
    int getMenuChoice();
    void searchItem();
    void printItemFrequency();
    void printItemHistogram();
};

#endif