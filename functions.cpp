#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits> // Include for numeric_limits.
#include "functions.h"

using namespace std;

// Takes user input value of 1-4 and checks to ensure it's an integer value.
int getMenuChoice()
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

void openFile()
{
    ifstream inFS; //input file stream

    // open provided data file
    inFS.open("CS210_Project_Three_Input_File.txt");

    // If file can't be found, then return an error.
    if (!inFS.is_open())
    {
        cout << "File does not exist." << endl;
        return;
    }
}