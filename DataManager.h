#ifndef DATAMANGER_H // guards
#define DATAMANGER_H

#include <string>
#include <fstream>

using namespace std;

class DataManager
{
private:
    string m_inputFilename;

public:
    DataManager(string t_inputFilename);
    void openFile();
    void writeData();
};

#endif