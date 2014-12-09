//
//  uniqueWords.cpp
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#include "uniqueWords.h"

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
    WordInfo thisWordInfo(freq, pageNum, str);
    docFreqPairs.insert(thisWordInfo);
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
    return docFreqPairs;
}


std::ostream& operator<<(std::ostream& os, const uniqueWords& obj)
{
    os << obj.name;
    return os;
}
void uniqueWords::incrementID(string SHA1)
{
    WordInfo newInfo(0,0,SHA1);
    docFreqPairs.find(newInfo).increment();
}