#include <iostream>
#include "XMLparser.h"

using namespace std;

int main()
{
    XMLParser* parser = new XMLParser();

    parser->readDocuments("WikiDumpPart1.xml");

    parser->printIndex(cout);

    std::cout << "Hello, bitches!\n";

    return 0;
}

