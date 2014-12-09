//
//  WordInfo.cpp
//  SearchEngine
//
//  Created by user on 12/2/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#include "WordInfo.h"

WordInfo::WordInfo(const WordInfo& wordInfo)
{
    this->freq = wordInfo.freq;
    this->setSHA1(wordInfo.SHA1);
    this->xmlPageNum = wordInfo.xmlPageNum;
}

WordInfo::WordInfo()
{
    freq = 0;
    xmlPageNum= 0;
    SHA1 = "falseSHA1id";
}
WordInfo::WordInfo(string s)
{
    freq = 1;
    xmlPageNum = 0;
    SHA1 = s;
}

WordInfo::WordInfo(int f, int n, string s)
{
    freq = f;
    xmlPageNum = n;
    SHA1 = s;
}
void WordInfo::setFreq(int i)
{
    freq += i;
}
void WordInfo::setPageNum(int i)
{
    xmlPageNum = i;
}
void WordInfo::setSHA1(string s)
{
    SHA1 = s;
}
void WordInfo::increment()
{
    freq++;
    std::cout << "To a Frequency of: " << this->freq << " With a SHA1 of: "<< this->SHA1 << " in Page #" << this->xmlPageNum << endl;
}
std::ostream& operator<<(std::ostream& os, const WordInfo& obj)
{
    string s;
    s = obj.getObjInfo();
    os << s;
    cout << s << flush;
    return os;
}
string WordInfo::getObjInfo() const
{
    stringstream streamy;
    string s;
    streamy << this->SHA1;
    streamy << " ";
    streamy << this->xmlPageNum;
    streamy << " ";
    s = streamy.str();
    return s;
}
