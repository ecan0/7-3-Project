#ifndef GROCERYCART_H // guards
#define GROCERYCART_H

#include <string>
#include <list>
#include <map>

using namespace std;

class GroceryCart
{
//fields for our master produce list and its associated map/dictionary for each produce item accompanied by how many times it occurs in produce list.
private:
    list<string> m_produceList;
    map<string,int> m_talliedItemPairs;

public:
    //grocery cart holds our master produce list
    GroceryCart(list<string> t_produceList);
    //accessor for produce list
    list<string> getRecordsList();
    //generate list of unique item count
    void generateItemCount();
    //map/dictionary to hold item's name and count in paired values
    map<string, int> getTalliedItemPairs();
    //mutator for item pairs
    void setTalliedItemPairs(map<string,int> t_talliedItemPairs);
    //reads user input between 1-4 to branch out into menu selections for search/print/exit functions.
    int getMenuChoice();
    //search for produce item in master grocery list based on user input 
    void searchItem();
    //print unique item and how many times it appears in produce list with number
    void printItemFrequency();
    //print unique item and how many times it appears in produce list with asterisk
    void printItemHistogram();
};

#endif