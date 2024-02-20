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

list<string> DataManager::getTextFile()
{
    return m_processedTextFile;
}

void DataManager::writeData(map<string, int> t_itemPairs)
{
    ofstream outFS;
    outFS.open("frequency.dat");
    if(!outFS.is_open())
    {
        cout << "Failure creating backup file." << endl;
        return;
    }
    for(const auto &items : t_itemPairs)
    {
        outFS << items.first << " " << items.second << endl;
    }

    outFS.close();
}