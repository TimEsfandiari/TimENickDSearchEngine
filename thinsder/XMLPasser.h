//
//  XMLPasser.h
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#ifndef __SearchEngine__XMLPasser__
#define __SearchEngine__XMLPasser__

#include <stdio.h>
//#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
//#include "XMLparser.h"

#include "rapidxml_utils.hpp"

using namespace std;

class XMLPasser
{
public:
    XMLPasser(); //Needs major work
    //void deleteDataSet(); maybe later
    //vector<string> returnDocInfo(string SHA1id); //returns all of document info based on ID
    void insertDocumentFileName(string SHA1id, string fileName); //inserts id and filename into dataSet
    void saveDataSet(); //saves the DataSet to a file
    void loadDataSet(); //loads Data from a file
    //unordered_map<string, string> getDataSet(); //returns this dataSet
private:
    //unordered_map<string,string> dataSet; //stores SHA1 ids, and their corresponding fileName
};

#endif /* defined(__SearchEngine__XMLPasser__) */
