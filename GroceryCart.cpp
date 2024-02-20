#include "GroceryCart.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
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
    cout << "Enter the item name you would like to search: " << endl;
    cin >> itemName;
    find(m_produceList.begin(), m_produceList.end(), itemName);
    cout << itemName << " appears " << count(m_produceList.begin(), m_produceList.end(), itemName) << "times." << endl;
}
// Takes user input value of 1-4 and checks to ensure it's an integer value.
int GroceryCart::getMenuChoice()
{
    int input;

    // loops until recieves correct input
    while (true)
    {
        cout << endl
             << "Enter menu choice 1-4.";

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
                 << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();                                         // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    return input;
}
 