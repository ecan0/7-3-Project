#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "DataManager.h"

using namespace std;

DataManager::DataManager(string t_inputFilename)
{
    m_inputFilename = t_inputFilename;
}

void DataManager::openFile()
{
    ifstream inFS; //input file stream
    string produceItem; //individual string/item in produce list that will be read from file

    // open provided data file
    inFS.open("CS210_Project_Three_Input_File.txt");

    // If file can't be found, then return an error.
    if (!inFS.is_open())
    {
        cout << "File does not exist." << endl;
        return;
    }

    //when the string is read in from the user file, add it to the main list created from the text file.
    while (inFS >> produceItem)
    {
        m_processedTextFile.push_front(produceItem);
    }
    
    //While we have the data, sort it so that way we can use standard library list functions on it later when we are searching and creating unique counts of data.
    m_processedTextFile.sort();

    //close file stream
    inFS.close();
}


//accessor for the list created from text file
list<string> DataManager::getTextFile()
{
    return m_processedTextFile;
}

//write the data from the item name and count pairs into frequency.dat
void DataManager::writeData(map<string, int> t_itemPairs)
{
    //create output stream and open a new file called frequency.dat
    ofstream outFS;
    outFS.open("frequency.dat");

    //check to see if file is creatable
    if(!outFS.is_open())
    {
        cout << "Failure creating backup file." << endl;
        return;
    }
    //for each item pair, write it to the output stream/frequency.dat.
    for(const auto &items : t_itemPairs)
    {
        outFS << items.first << " " << items.second << endl;
    }

    //close output stream
    outFS.close();
}