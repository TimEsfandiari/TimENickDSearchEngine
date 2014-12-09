#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <fstream>
#include "VirtualIndexer.h"
#include "AVLTree.hpp"
#include "uniqueWords.h"
#include <unordered_map>
#include <sstream>
#include "WordInfo.h"

class HashTable : public VirtualIndexer
{
private:
    unordered_map<string, WordInfo> table;
    unordered_map<string, WordInfo>::iterator it;
    string indexSaveFile;

public:
    HashTable();
    virtual ~HashTable();
    virtual void insert(string word, WordInfo info);
    virtual AVLTree<WordInfo> search(string word);
    virtual void deleteIndex();
    virtual void saveIndex();
    virtual void printIndex(ostream& ostrm);
    virtual bool isFound(string word);
    virtual void incrementFrequency(string word, string SHA1, int freq);


};

#endif // HASHTABLE_H
