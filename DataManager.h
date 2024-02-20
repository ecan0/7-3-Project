#ifndef DATAMANGER_H // guards
#define DATAMANGER_H

#include <string>
#include <list>
#include <map>
#include <fstream>

using namespace std;

class DataManager
{
private:
    list<string> m_processedTextFile;
    string m_inputFilename;

public:
    DataManager(string t_inputFilename);
    void openFile();
    void writeData(map<string,int> t_talliedItemPairs);
    list<string> getTextFile();
};

#endif