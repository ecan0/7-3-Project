#include <iostream>
#include <iomanip>
#include <string>
#include "GroceryCart.h"
#include "DataManager.h"

using namespace std;

int main()
{
    DataManager dataFiles = DataManager("CS210_Project_Three_Input_File.txt");
    dataFiles.openFile();
    list<string> compiledItemList = dataFiles.getTextFile();
    GroceryCart groceryRecords = GroceryCart(compiledItemList);
    groceryRecords.generateItemCount();
    dataFiles.writeData(groceryRecords.getTalliedItemPairs());
    int menuInput;

    cout << "Welcome to the Corner Grocer item-tracking application!\n" 
    << "Please type one of the following menu options:\n"
    << "1 - Search an item based off its name in the list (e.g. Apples) and how many purchases occured\n"
    << "2 - Print all produce sold and the corresponding number of items sold\n"
    << "3 - Print a hisogram of all produce sold denoted by asteriks for each sale.\n"
    << "4 - Exit the application.\n" << endl;

    do
    {
        cout << "Please enter an input between 1-4.\n" << endl;
        menuInput = groceryRecords.getMenuChoice();
        switch(menuInput)
        {
            case 1:
                groceryRecords.searchItem();
                break;
            case 2:
                groceryRecords.printItemFrequency();
                break;
            case 3:
                groceryRecords.printItemHistogram();
                break;
            case 4:
                cout << "Exiting program.";
                return 0;
            default:
                cout << "Invalid entry." << endl;
                break;
        }
    } while (true);
}