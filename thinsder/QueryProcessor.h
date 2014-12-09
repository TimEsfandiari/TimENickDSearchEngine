//
//  QueryProcessor.h
//  SearchEngine
//
//  Created by user on 12/5/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#ifndef __SearchEngine__QueryProcessor__
#define __SearchEngine__QueryProcessor__

#include <stdio.h>
#include <sstream>
#include "XMLparser.h"
#include "uniqueWords.h"
#include "WordInfo.h"

class QueryProcessor
{
public:
    QueryProcessor();
    //~QueryProcessor(); not necessary, no dynamic memory here,though maybe i make xmlparser a pointer/dynamically call it.
    void establishIndex(char* fileName ); //accepts additional files to add to index if necessary;
        //i need to write code to check to see if index was loaded from file, and to handle loading/building/adding file in side the idexer/parser;
    void processManager(int QueryType);  //handles query's from textFile or terminal, accepts int to determine mode.
    uniqueWords returnAndQuery(stringstream& wordList);
    uniqueWords returnSingleQuery(stringstream& wordList);
    uniqueWords returnOrQuery(stringstream& wordList);
    void removeNotQuery(string& notWord, stringstream& toBeCleaned);   //remove's documents that contain the notWord from the ss to be cleaned.
private:
    XMLParser thisParser;
};

#endif /* defined(__SearchEngine__QueryProcessor__) */
