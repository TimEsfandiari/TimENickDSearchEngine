#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "StopWorder.h"
#include "IndexDriver.h"
#include "XMLPasser.h"
#include "VirtualIndexer.h"
#include "AVLIndexer.h"
#include "uniqueWords.h"
//#include <unordered_map>
#include "AVLTree.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class XMLParser
{
private:
    int dataSetSize;
    stopWorder stopper;
    XMLPasser passer;
    IndexDriver *index;
public:
    XMLParser(); //Needs Major Work
    void fileSplitter();
    void readDocuments(char* fileName);
    void setXMLPasser(XMLPasser& passer);
    void setStopper(stopWorder& stopper);
    void linkIndex(IndexDriver& indexer);
    int getDataSetSize();
    void setDataSetSize(int size);
    void deleteSplitFiles(); // maybe impliment for stress testing
    string getDocumentInfo(string id); //returns all the info on a Document, based on SHA1 id.
    void printIndex(ostream& ostrm);
};

#endif // XMLPARSER_H
