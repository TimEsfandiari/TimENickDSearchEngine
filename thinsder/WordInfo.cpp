//
//  WordInfo.cpp
//  SearchEngine
//
//  Created by user on 12/2/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#include "WordInfo.h"

WordInfo::WordInfo()
{
    freq = 0;
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
}
//bool WordInfo::operator<(const WordInfo& second) const
//{
//    return (this->freq < second.freq);
//}
