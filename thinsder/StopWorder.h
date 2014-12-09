#ifndef STOPWORDER_H
#define STOPWORDER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "AVLTree.hpp"
#include <string>

class stopWorder
{
private:
    AVLTree<std::string> stopWords;
public:
    stopWorder(); // Needs major work
    void loadStopWords();   //Loads stop words into stopWords tree
    std::string removeStopWords(std::stringstream &wordList);  //returns cleaned stringstream
    bool checkIfStop(std::string word); //returns true if it is a stop word
    bool punctuationCheck(char letter); //returns is character is ! , . ; etc...
    void checkIfLoaded();   //determines if avl tree is loaded
};

#endif // STOPWORDER_H
 