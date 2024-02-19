#ifdef GROCERYCART_H // guards
#define GROCERYCART_H

#include <string>

using namespace std;

class GroceryCart
{
private:
    list<string> m_produceList;
public:
    GroceryList(list<string> t_produceList);
    void AddProduce();
    int getMenuChoice();
    void searchItem();
    void printItemFrequency();
    void printItemHistogram();
}

#endif