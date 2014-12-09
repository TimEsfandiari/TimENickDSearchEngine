//
//  WordInfo.h
//  SearchEngine
//
//  Created by user on 12/2/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#ifndef __SearchEngine__WordInfo__
#define __SearchEngine__WordInfo__

#include <stdio.h>
#include <string>

using namespace std;

class WordInfo
{
private:
    int freq;
    int xmlPageNum;
    string SHA1;
    
public:
    WordInfo();
    WordInfo(string s);
    WordInfo(int f, int n, string s);
    void setFreq(int i);
    void setPageNum(int i);
    void setSHA1(string s);
    void increment();
    //bool operator<(const WordInfo& second) const;
    friend bool operator< (const WordInfo& lhs, const WordInfo& rhs)
    {
        return (lhs.freq < rhs.freq);
    }
    friend bool operator== (const WordInfo& lhs, const WordInfo& rhs)
    {
        return (lhs.SHA1 == rhs.SHA1);
    }
    friend bool operator== (const WordInfo& lhs, const string& rhs)
    {
        return (lhs.SHA1 == rhs);
    }
    friend bool operator> (const WordInfo& lhs, const WordInfo& rhs)
    {
        return !(lhs < rhs);
    }
    WordInfo& operator+=(const WordInfo& rhs)
    {
        this->freq += rhs.freq;
        return *this;
    }
};


#endif /* defined(__SearchEngine__WordInfo__) */
