//
//  IndexDriver.h
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#ifndef __SearchEngine__IndexDriver__
#define __SearchEngine__IndexDriver__

#include <stdio.h>
#include "AVLIndexer.h"
#include "WordInfo.h"
#include "AVLTree.hpp"
#include "VirtualIndexer.h"
//#include "HashTableIndexer.h" later

class IndexDriver
{
public:
    IndexDriver(); //Needs Major Work
    IndexDriver(int i); //Accepts 0 for AVLTree or 1 for HashTable currently no functioning hash table implimentation
    void insert(string word, string SHA1id, int frequency, int pageNum); //Calls AVL/HashTable specific
    AVLTree<WordInfo> search(string word); //returns frequency and docid pairing list
    void deleteIndex(); //Calls AVL/HashTable specific delete
    void saveIndex();   //Calls AVL/HashTable specific save
    void printIndex(ostream& ostrm);    //Calls AVL/HashTable specific print
    bool isFound(string word);
private:
    VirtualIndexer *indexer;
};

#endif /* defined(__SearchEngine__IndexDriver__) */
