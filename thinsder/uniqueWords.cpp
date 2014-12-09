//
//  uniqueWords.cpp
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#include "uniqueWords.h"
uniqueWords::uniqueWords(const uniqueWords& word)
{
    this->name = word.name;
    this->docFreqPairs = word.docFreqPairs;
}

uniqueWords::uniqueWords()
{
    name = "";
}

void uniqueWords::setName(string s)
{
    name = s;
}

uniqueWords::uniqueWords(string s)
{
    name = s;
}

string uniqueWords::getName()
{
    return name;
}

void uniqueWords::setDocFreqPair(string str, int freq , int pageNum)
{
    WordInfo* thisWordInfo = new WordInfo(freq, pageNum, str);
    docFreqPairs.insert(*thisWordInfo);
}

/*bool uniqueWords::operator==(const uniqueWords& second)
{
    if(this->name == second.name)
        return true;
    else
        return false;
}*/

AVLTree<WordInfo> uniqueWords::getDocFreqPairs()
{
    return this->docFreqPairs;
}


std::ostream& operator<<(std::ostream& os, const uniqueWords& obj)
{
    os << obj.name;
    //obj.docFreqPairs.print(os);
    os << endl;
    return os;
}
void uniqueWords::incrementID(string SHA1)
{
    cout << "Incrementing Word: " << this->getName() << "-" << std::flush;
    if(docFreqPairs.isFound(SHA1))
        docFreqPairs.find(SHA1).increment();
    else
        docFreqPairs.insert(SHA1);
}
