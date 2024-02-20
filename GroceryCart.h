#ifndef GROCERYCART_H // guards
#define GROCERYCART_H

#include <string>
#include <list>
#include <map>

using namespace std;

class GroceryCart
{
private:
    list<string> m_produceList;
    map<string,int> m_talliedItemPairs;

public:
    GroceryCart(list<string> t_produceList);
    list<string> getRecordsList();
    void generateItemCount();
    map<string, int> getTalliedItemPairs();
    int getMenuChoice();
    void searchItem();
    void printItemFrequency();
    void printItemHistogram();
};

#endif