//
//  AVLIndexer.h
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#ifndef __SearchEngine__AVLIndexer__
#define __SearchEngine__AVLIndexer__

#include <stdio.h>
#include <fstream>
#include "VirtualIndexer.h"
#include "AVLTree.hpp"
#include "uniqueWords.h"
#include <sstream>
#include "WordInfo.h"

class AVLIndexer : public VirtualIndexer
{
public:
    AVLIndexer();   //Needs major work
    virtual ~AVLIndexer();
    virtual void insert(string word, string SHA1id, int frequency, int pageNum);
    virtual AVLTree<WordInfo> search(string word); // returns frequency and docid pairing list
    virtual void deleteIndex(); //deletes AVLtree
    virtual void saveIndex();   //Saves AVLTree to fle
    virtual void printIndex(ostream& ostrm);    //Prints AVLTree to desinted ostream
    virtual bool isFound(string word);
    virtual void incrementFrequency(string word, string SHA1, int freq);
    
private:
    AVLTree<uniqueWords> indexWords;
    string indexSaveFile;
    
};

#endif /* defined(__SearchEngine__AVLIndexer__) */
