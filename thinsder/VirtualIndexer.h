//
//  VirtualIndexer.h
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#ifndef SearchEngine_VirtualIndexer_h
#define SearchEngine_VirtualIndexer_h

#include <string>
#include <iostream>
//#include <unordered_map>
#include <ostream>
#include <fstream>
#include "WordInfo.h"
#include "AVLTree.hpp"
#include "uniqueWords.h"

using namespace std;

class VirtualIndexer
{
public:

    virtual ~VirtualIndexer() = 0;
    virtual void insert(string word, string SHA1id, int frequency, int pageNum) = 0;
    virtual AVLTree<WordInfo> search(string word) = 0;
    virtual void deleteIndex() = 0;
    virtual void saveIndex() = 0;
    virtual void printIndex(ostream& ostrm) = 0;
    virtual bool isFound(string word) = 0;
    virtual void incrementFrequency(string word, string SHA1, int freq) = 0;
    
private:
    string indexSaveFile;
    
};

#endif
