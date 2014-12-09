//
//  QueryProcessor.cpp
//  SearchEngine
//
//  Created by user on 12/5/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#include "QueryProcessor.h"
QueryProcessor::QueryProcessor()
{

}

//~QueryProcessor(); not necessary, no dynamic memory here,though maybe i make xmlparser a pointer/dynamically call it.
void QueryProcessor::establishIndex()
{
    //This is where you pick the files to be added. WikiDumpPart(1-179).xml
    string namePart = "WikiDumpPart";
    for(int i = 1; i <=179; i++)
    {
        stringstream fileName;
        fileName << namePart;
        fileName << i;
        fileName << ".xml";
        string tmp = fileName.str();
        const char* cstring = tmp.c_str();
        thisParser.readDocuments(cstring , i);
        cout << "Parsed Doc " << i << endl;
    }
}

void QueryProcessor::addNewFile(const char* fileName ) //accepts additional files to add to index if necessary;
{
    thisParser.readDocuments(fileName, 180);
}
    //i need to write code to check to see if index was loaded from file, and to handle loading/building/adding file in side the idexer/parser;
void QueryProcessor::processManager(int QueryType)  //handles query's from textFile or terminal, accepts int to determine mode.
{

}

uniqueWords QueryProcessor::returnAndQuery(stringstream& wordList)
{

}

string QueryProcessor::returnSingleQuery(stringstream& wordList)
{
    stopper.removeStopWords(wordList);
    stringstream bigbaddy;
    string s;
    while(!wordList.eof())
    {
        wordList >> s;
        bigbaddy << thisParser.getWordDocuments(s);
        cout << thisParser.getWordDocuments(s) << endl;
    }
}

uniqueWords QueryProcessor::returnOrQuery(stringstream& wordList)
{

}

void QueryProcessor::removeNotQuery(string& notWord, stringstream& toBeCleaned)
{

}
