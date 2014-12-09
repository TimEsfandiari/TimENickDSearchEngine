/*Will load the xml document into
 */
#include "XMLparser.h"

using namespace rapidxml;

XMLParser::XMLParser()
{
    index = new IndexDriver();
}
void XMLParser::fileSplitter()
{
    //run pearl script to split files
}
void XMLParser::readDocuments(const char* fileName, int num)
{
    file<> xmlFile(fileName);
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    xml_node<>* node = doc.first_node();
    node = node->first_node("page");
    while(node)
    {
        string words;
        string SHA1;
        xml_node<>* thisPageInfo = node->first_node("revision");
        words = thisPageInfo->first_node("text")->value();
        std::stringstream ss;
        ss << words;
        ss << stopper.removeStopWords(ss);
        SHA1 = thisPageInfo->first_node("sha1")->value();
        while (!ss.eof())
        {
            string finalWord;
            ss >> finalWord;
            index->insert(finalWord, SHA1, num, 1); //adds word into index along with SHA1 id and number of xml document info can be found in.
            index->search(finalWord).print(cout); // just for testing
        }
        node = node->next_sibling();

    }
    cout << "Finished Document" << endl;
}
void XMLParser::setStopper(stopWorder& stopper)
{
    this->stopper = stopper;
}
int XMLParser::getDataSetSize()
{
    int i = 0;
    return i;
}
void XMLParser::setDataSetSize(int size)
{
    dataSetSize = size;
}
//void XMLParser::deleteSplitFiles(); // maybe impliment for stress testing
string XMLParser::getDocumentInfo(string id) //returns all the info on a Document, based on SHA1 id.
{

    string s = " ";
    
    return s;
}
void XMLParser::linkIndex(IndexDriver &indexer)
{
    this->index = &indexer;
}

void XMLParser::printIndex(ostream& ostrm)
{
    //index->printIndex(ostrm);
    index->saveIndex();
}

string XMLParser::getWordDocuments(string word)
{
    stringstream streamy;
    this->index->search(word).returnFunc(streamy);
    string s = streamy.str();
    return s;
}
