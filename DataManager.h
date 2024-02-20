#ifndef DATAMANGER_H // guards
#define DATAMANGER_H

#include <string>
#include <list>
#include <map>
#include <fstream>

using namespace std;

//Class definition for DataManager that will open our provided grocery list file and write data to a backup file named frequency.dat.
class DataManager
{
//fields for the processed text file and the input file name
private:
    list<string> m_processedTextFile;
    string m_inputFilename;


public:
    //class will take file name to perform i/o functions
    DataManager(string t_inputFilename);
    //function to open provided file
    void openFile();
    //function to write data based on item name/count pair
    void writeData(map<string,int> t_talliedItemPairs);
    //accessor for the list that is generated from the text file
    list<string> getTextFile();
};

#endif