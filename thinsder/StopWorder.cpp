#include "StopWorder.h"

stopWorder::stopWorder()
{
    loadStopWords();
}
void stopWorder::loadStopWords()
{
    std::ifstream fin("StopWords.txt");
    if(fin.is_open())
        std::cout << "File Opened";
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
    std::string final;
    std::string temp;
    while(!wordList.eof())
    {
        wordList >> temp;
        if(checkIfStop(temp) == false)
            final += temp + " ";
        else
            final += "";
    }
    wordList.clear();
    wordList >> final;
    return final;
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
