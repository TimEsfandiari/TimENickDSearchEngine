#include <iostream>
#include "XMLparser.h"
#include "IndexDriver.h"
#include "QueryProcessor.h"

using namespace std;

int main()
{
    //XMLParser* parser = new XMLParser();

    //parser->readDocuments("WikiDumpPart1.xml" , 1);

    //parser->printIndex(cout);
    QueryProcessor proccess;
    proccess.establishIndex();
    stringstream streamy;
    string s = "This word more words run running jog poke time weird";
    streamy << s;
    //proccess.returnSingleQuery(streamy);
    //proccess.addNewFile("this.xml");


    cout << "Hello, bitches!\n";

    return 0;
}

