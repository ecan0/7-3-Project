#include <iostream>
#include <iomanip>
#include <string>
//header files with class definitions
#include "GroceryCart.h"
#include "DataManager.h"

using namespace std;

int main()
{
    //Initialize DataManager object with the filename of our provided produce list for the project.
    DataManager dataFiles = DataManager("CS210_Project_Three_Input_File.txt");
    dataFiles.openFile();
    //Assuming a correct text file was found and opened, store it in the compiled item list then pass it to our GroceryCart that will contain it moving forward.
    list<string> compiledItemList = dataFiles.getTextFile();
    GroceryCart groceryRecords = GroceryCart(compiledItemList);
    //Create a count of each unique item in the produce list with its name and how many times it occurs.
    groceryRecords.generateItemCount();
    //Based on the mapped values of items and their counts, write that data with the DataManager to frequency.dat.
    dataFiles.writeData(groceryRecords.getTalliedItemPairs());

    //user input between 1 and 4
    int menuInput;

    cout << "Welcome to the Corner Grocer item-tracking application!\n" 
    << "Please type one of the following menu options:\n"
    << "1 - Search an item based off its name in the list (e.g. Apples) and how many purchases occured\n"
    << "2 - Print all produce sold and the corresponding number of items sold\n"
    << "3 - Print a hisogram of all produce sold denoted by asterisk for each sale.\n"
    << "4 - Exit the application." << endl;

    do
    {
        cout << "\nPlease enter an input between 1-4.\n" << endl;
        //get user input between 1 and 4 for menu selection
        menuInput = groceryRecords.getMenuChoice();
        switch(menuInput)
        {
            //Option 1 searches for produce item based on user input.
            case 1:
                groceryRecords.searchItem();
                break;
            //Open 2 prints item name followed by the frequency of how many times it occurs in the produce list.
            case 2:
                groceryRecords.printItemFrequency();
                break;
            //Option 3 prints item histogram with an asterisk for each number of item occurrences in produce list.
            case 3:
                groceryRecords.printItemHistogram();
                break;
            //Option 4 exits program.
            case 4:
                cout << "Exiting program.";
                return 0;
            //Anything other than 1-4 will reach default value. Additional error handling found in getMenuChoice().
            default:
                cout << "Invalid entry." << endl;
                break;
        }
    } while (true);
}