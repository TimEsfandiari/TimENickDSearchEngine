//
//  AVLIndexer.cpp
//  SearchEngine
//
//  Created by user on 11/24/14.
//  Copyright (c) 2014 user. All rights reserved.
//

#include "AVLIndexer.h"

AVLIndexer::AVLIndexer()
{
    //implement loading from saved index l8er
    indexSaveFile = "filePath.txt";
}
AVLIndexer::~AVLIndexer()
{
    //indexWords.makeEmpty();
}
void AVLIndexer::insert(string word, string SHA1id, int frequency, int pageNum)
{
    uniqueWords thisWord;
    thisWord.setName(word);
    thisWord.setDocFreqPair(SHA1id, frequency, pageNum);
    indexWords.insert(thisWord);
    
}
AVLTree<WordInfo> AVLIndexer::search(string word)
{
    //uniqueWords thisWord(word);
    //uniqueWords newWord = indexWords.find(thisWord);
    return this->indexWords.find(word).getDocFreqPairs(); //get docfreqpairs returns a list of instances of the word and frequency on that page.
}
void AVLIndexer::deleteIndex()
{
    this->indexWords.makeEmpty();
}
void AVLIndexer::saveIndex()
{
    fstream fout(this->indexSaveFile.c_str());
    if(fout.is_open())
    {
        this->indexWords.print(fout);
    }
    else
        cout << "Couldn't Open File For Index Output" << endl;
    fout.close();
}
void AVLIndexer::printIndex(ostream& ostrm)
{
    this->indexWords.print(ostrm);
}
bool AVLIndexer::isFound(string word)
{
    if(indexWords.isFound(word))
    {
        return true;
    }
    else
        return false;
}
void AVLIndexer::incrementFrequency(string word, string SHA1, int freq)
{
    indexWords.find(word).setDocFreqPair(SHA1, freq);
}
