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
void XMLParser::readDocuments(char* fileName)
{
    file<> xmlFile(fileName);
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    xml_node<>* node = doc.first_node();
    node = node->first_node("page");
    for (int i = 0; i < 1; i++) //because of number of xml files
    {
        while(node)
        {
            string words;
            string SHA1;
            xml_node<>* thisPageInfo = node->first_node("revision");
            words = thisPageInfo->first_node("text")->value();
            std::stringstream ss;
            ss << words;
            //stopper.removeStopWords(ss);
            words = ss.str();
            SHA1 = thisPageInfo->first_node("sha1")->value();
            while (!ss.eof())
            {
                //cout << "i made it here" << endl;

                string finalWord;
                ss >> finalWord;
                uniqueWords thisWord(finalWord);
                if(index->isFound(finalWord))
                {
                    WordInfo thisWordInfo(SHA1);
                    index->search(finalWord).find(thisWordInfo).increment();
                }
                else
                {
                    index->insert(finalWord, SHA1, i, 1); //adds word into index along with SHA1 id and number of xml document info can be found in.
                }
                //make sure insert handles double and increasing frequency;
            }
            node = node->next_sibling();
        }
    }
}
void XMLParser::setXMLPasser(XMLPasser& passer)
{
    this->passer = passer;
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
    index->printIndex(ostrm);
}
