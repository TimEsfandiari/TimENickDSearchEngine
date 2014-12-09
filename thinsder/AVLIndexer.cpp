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

}
void AVLIndexer::insert(string word, string SHA1id, int frequency, int pageNum)
{
    uniqueWords* thisWord = new uniqueWords(word);
    //uniqueWords thisWord(word);
    thisWord->setDocFreqPair(SHA1id, frequency, pageNum);
    if(indexWords.isFound(word))
    {
        indexWords.find(word).incrementID(SHA1id);
    }
    else
    {
        indexWords.insert(*thisWord);
        //cout << "Inserted Word: " << word << " on page SHA1: " << SHA1id << " with Freq: " << frequency << " in file #" << pageNum << endl;
    }
}
AVLTree<WordInfo> AVLIndexer::search(string word)
{
    return this->indexWords.find(word).getDocFreqPairs(); //get docfreqpairs returns a list of instances of the word and frequency on that page.
}
void AVLIndexer::deleteIndex()
{
}
void AVLIndexer::saveIndex()
{
    ofstream fout(this->indexSaveFile.c_str());
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
    cout << "Frequency Increased to: " << indexWords.find(word);
}
