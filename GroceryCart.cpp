#include "GroceryCart.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <limits> // Include for numeric_limits.

using namespace std;

GroceryCart::GroceryCart(list<string> t_produceList)
{
    m_produceList = t_produceList;
}

list<string> GroceryCart::getRecordsList()
{
    return m_produceList;
}

void GroceryCart::searchItem()
{
    string itemName;
    list<string> records = m_produceList;
    cout << "Enter the item name you would like to search: " << endl;
    cin >> itemName;
    find(records.begin(), records.end(), itemName);
    cout << itemName << " appears " << count(records.begin(), records.end(), itemName) << " times." << endl;
}

void GroceryCart::printItemFrequency()
{
    map<string, int> itemFrequency;
    list<string> records = m_produceList;
    int frequency;
    for (auto const& item : records)
    {
        frequency = count(records.begin(), records.end(), item);
        itemFrequency.emplace(item, frequency);
    }
    for(const auto &itemPair: itemFrequency)
    {
        cout << itemPair.first << " " << itemPair.second << endl;
    }
}

void GroceryCart::printItemHistogram()
{
    map<string, int> itemHistogram;
    list<string> records = m_produceList;
    int frequency;
    for (auto const& item : records)
    {
        frequency = count(records.begin(), records.end(), item);
        itemHistogram.emplace(item, frequency);
    }
    for(const auto &itemPair: itemHistogram)
    {
        cout << itemPair.first << " " << string(itemPair.second, '*') << endl;
    }
}


// Takes user input value of 1-4 and checks to ensure it's an integer value.
int GroceryCart::getMenuChoice()
{
    int input;

    // loops until recieves correct input
    while (true)
    {
        // Check if the input is an integer
        if (cin >> input)
        {
            // Check if the input is within the valid range
            if (input >= 1 && input <= 4)
            {
                break;
            }
            else
            {
                cout << endl
                     << "Invalid choice. Please enter a number between 1 and 4." << endl;
            }
        }
        else
        {
            // Handle non-integer input
            cout << endl
                 << "Invalid input. Please enter a valid integer between 1 and 4." << endl;
            cin.clear();                                         // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    return input;
}
 