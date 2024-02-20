#include <iostream>
#include <iomanip>
#include <string>
#include "GroceryCart.h"
#include "DataManager.h"

using namespace std;

int main()
{
    DataManager dataFiles = DataManager("CS210_Project_Three_Input_File.txt");
    list<string> textFile = dataFiles.getTextList();
    GroceryCart groceryRecords = GroceryCart(textFile);
    int menuInput;

    do
    {
        cout << "Please enter an input between 1-3." << endl;
        menuInput = groceryRecords.getMenuChoice();
        switch(menuInput)
        {
            case 1:
                groceryRecords.searchItem();
            case 2:
            case 3:
            case 4:
                cout << "Exiting program.";
                return 0;
            default:
                cout << "Invalid entry." << endl;
                break;
        }
    } while (true);

    return 0;
}