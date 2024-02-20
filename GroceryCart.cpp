#include "GroceryCart.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

//Initialize our GroceryCart object that will hold our main produce list (untallied/unsorted).
GroceryCart::GroceryCart(list<string> t_produceList)
{
    m_produceList = t_produceList;
}

//Accessor for the produce list
list<string> GroceryCart::getRecordsList()
{
    return m_produceList;
}

//Before the item is sorted/tallied, look for how many occurrences of the item are in the produce list.
void GroceryCart::searchItem()
{
    string itemName;
    list<string> records = m_produceList;
    cout << "Enter the item name you would like to search: " << endl;
    cin >> itemName;
    //Use the find function to enumurate through the user input from the beginning to end of list, and look for the item name.
    find(records.begin(), records.end(), itemName);
    //output the item name, and how many times it appears based on the call of the count function.
    cout << "\n" << itemName << " appears " << count(records.begin(), records.end(), itemName) << " times." << endl;
}

//Generate a new map with UNIQUE pairs for each item and how many times it occurs in the list after being sorted (sorting occurs in DataManager.)
void GroceryCart::generateItemCount()
{
    //Create a new map of the item name and the number of times it occurs in the main produce list.
    map<string, int> itemFrequency;
    //the produce list to search through
    list<string> records = m_produceList;
    int frequency;
    //for each item in the produce list/records, set the frequency to the count of how many times the item appears in the list once and one time only.
    for (auto const& item : records)
    {
        frequency = count(records.begin(), records.end(), item);
        itemFrequency.emplace(item, frequency); // then, add the item name and the count of how many times it goes in the list to the map/dictionary.
    }
    //We have now generated a tallied item list, we will pass it into the mutator in order to set it within our class.
    setTalliedItemPairs(itemFrequency);
}

//Accessor for tallied items map
map<string, int> GroceryCart::getTalliedItemPairs()
{
    return m_talliedItemPairs;
}

//Mutator for tallied items map
void GroceryCart::setTalliedItemPairs(map<string, int> t_talliedItemPairs)
{
    m_talliedItemPairs = t_talliedItemPairs;
}

//For each item pair in the tallied pairs map, print out the name of the item, a space, and the number of occurances that was found in the main produce list.
void GroceryCart::printItemFrequency()
{
    for(const auto &itemPair: getTalliedItemPairs())
    {
        cout << itemPair.first << " " << itemPair.second << endl;
    }
}

//For each item pair in the tallied pairs map, print out the name of the item, a space, and the an asterisk for the number of occurances found in the main produce list.
void GroceryCart::printItemHistogram()
{
    for(const auto &itemPair: getTalliedItemPairs())
    {
        cout << itemPair.first << " " << std::string(static_cast<unsigned int>(itemPair.second), '*')  << endl;
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
 