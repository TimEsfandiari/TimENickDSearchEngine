//
//  uniqueWords.h
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#ifndef __SearchEngine__uniqueWords__
#define __SearchEngine__uniqueWords__

#include <stdio.h>
#include <string>
//#include <unordered_map>
#include "AVLTree.hpp"
#include "WordInfo.h"

using namespace std;

class uniqueWords
{
public:
    uniqueWords(); //needs major work
    uniqueWords(const uniqueWords& word);
    uniqueWords(string s);
    void setName(string s);
    string getName();
    void incrementID(string SHA1);
    void setDocFreqPair(string str, int freq, int pageNum = 0); //use in modify docFreqPairs from outside of this class
    friend bool operator==(const uniqueWords& first, const uniqueWords& second)
    {
        return (first.name == second.name);
    }
    friend bool operator<(const uniqueWords& first, const uniqueWords& second)
    {
        return (first.name < second.name);
    }
    friend bool operator>(const uniqueWords& first, const uniqueWords& second)
    {
        return !(first < second);
    }
    uniqueWords& operator+=(const uniqueWords& rhs)
    {
        //this needs to be fixxed;
        return *this;
    }
    AVLTree<WordInfo> getDocFreqPairs();
    friend std::ostream& operator<<(std::ostream& os, const uniqueWords& obj);

private:
    string name;
    AVLTree<WordInfo> docFreqPairs; //holds each page by SHA1 id, freq on that page, and the XML document that page is contained in.
};

#endif /* defined(__SearchEngine__uniqueWords__) */
