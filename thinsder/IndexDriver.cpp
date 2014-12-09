//
//  IndexDriver.cpp
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#include "IndexDriver.h"
IndexDriver::IndexDriver()
{
    indexer = new AVLIndexer();
}
IndexDriver::IndexDriver(int i)
{
    if (i == 0)
        indexer = new AVLIndexer();
    else;
        //indexer = new HashTable();
}
//added int pageNum to this
void IndexDriver::insert(string word, string SHA1id, int frequency, int pageNum)
{
    this->indexer->insert(word, SHA1id, frequency, pageNum);
}

AVLTree<WordInfo> IndexDriver::search(string word)
{
    return this->indexer->search(word);
}
void IndexDriver::deleteIndex()
{
    this->indexer->deleteIndex();
}
void IndexDriver::saveIndex()
{
    this->indexer->saveIndex();
}
void IndexDriver::printIndex(ostream& ostrm)
{
    this->indexer->printIndex(ostrm);
}
bool IndexDriver::isFound(string word)
{
    this->indexer->isFound(word);
}
