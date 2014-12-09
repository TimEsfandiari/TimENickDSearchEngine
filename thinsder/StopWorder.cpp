#include "StopWorder.h"

stopWorder::stopWorder()
{
    loadStopWords();
}
void stopWorder::loadStopWords()
{
    std::ifstream fin("StopWords.txt");
    if(fin.is_open())
        std::cout << "File Opened" << std::endl;
    std::string word;
    int size = 0;
    while((!fin.eof()) && (fin.is_open()))
    {
        fin >> word;
        stopWords.insert(word);
        size++;
    }
    /* Test for Working load;
     */
    if(stopWords.isEmpty())
        std::cout << "It didnt work";
}

std::string stopWorder::removeStopWords(std::stringstream &wordList)
{
    stringstream final;
    std::string temp;
    while(!wordList.eof())
    {
        wordList >> temp;
        clean(temp);
        if(checkIfStop(temp) == false)
            final << temp << " ";
        else
            final << " ";
    }
    wordList.clear();
    wordList << final.str();
    return final.str();
}

bool stopWorder::checkIfStop(std::string word)
{
    if(stopWords.isFound(word))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stopWorder::punctuationCheck(char letter)
{
    int number = letter;
    if((number >= 65 && number <= 90) || (number >= 97 && number <= 122))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void stopWorder::checkIfLoaded()
{
    if(stopWords.isEmpty())
        std::cout << "Its EMPTY";
    else
        std::cout << "Its Not Empty";
}

void stopWorder::clean(string& s)
{
    string result;
    std::remove_copy_if(s.begin(), s.end(),
                            std::back_inserter(result), //Store output
                            std::ptr_fun<int, int>(&std::ispunct)
                           );
    s = result;
    char* c = new char[s.size()];
    strcpy(c, s.c_str());
    c[stem(c, 0, strlen(c) - 1)] = '\0';
    s = c;
}
