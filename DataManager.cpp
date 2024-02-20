#include <string>
#include <iostream>
#include <fstream>
#include "DataManager.h"

using namespace std;

DataManager::DataManager(string t_inputFilename)
{
    m_inputFilename = t_inputFilename;
}

void DataManager::openFile()
{
    ifstream inFS; //input file stream
    string produceItem;

    // open provided data file
    inFS.open("CS210_Project_Three_Input_File.txt");

    // If file can't be found, then return an error.
    if (!inFS.is_open())
    {
        cout << "File does not exist." << endl;
        return;
    }

    while (inFS >> produceItem)
    {
        m_processedTextFile.push_front(produceItem);
    }

    m_processedTextFile.sort();

    inFS.close();
}

list<string> DataManager::getTextList()
{
    return m_processedTextFile;
}