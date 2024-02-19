#include <iostream>
#include <iomanip>
#include <string>
#include <limits> // Include for numeric_limits.
#include "functions.h"

using namespace std;

//Takes user input value of 1-4 and checks to ensure it's an integer value.
int getMenuChoice()
{
  int input;

  //loops until recieves correct input
  while (true)
  {
    cout << endl
         << "Enter menu choice 1-3.";

    // Check if the input is an integer
    if (cin >> input)
    {
      // Check if the input is within the valid range
      if (input >= 1 && input <= 3)
      {
        break;
      }
      else
      {
        cout << endl << "Invalid choice. Please enter a number between 1 and 3." << endl;
      }
    }
    else
    {
      // Handle non-integer input
      cout << endl << "Invalid input. Please enter a valid integer." << endl;
      cin.clear();                                         // Clear the error state
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
  }
  return input;
}