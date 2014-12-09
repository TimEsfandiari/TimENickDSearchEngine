#include "HashTable.h"

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
    delete table;
}

//inserts element into the index
void HashTable::insert(string word, WordInfo info)
{
    table.insert(make_pair(word, info));
}

// searches the hash table for a word
unordered_map<string, WordInfo> HashTable::search(string word)
{
    //create iterator
    unordered_map<string, WordInfo>::const_iterator got = table.find (word);
    cout << "Searching..." << endl;

    //searches
    if (got == table.end())
        cout << "Search not found." << endl;
    else
        cout << got->first << " is " << got->second << endl;

    return 0;

}

//deletes all elements in index
void HashTable::deleteIndex()
{
    table.erase( table.begin(), table.end() );
}


void HashTable::saveIndex()
{
    ofstream file;
    file.open("HashSave.txt");
    file << "Hash Table Contains:" << endl;
    for (auto it = table.begin(); it != table.end(); ++it)
      file << it->first << " : " << it->second << endl;
    file << endl;

}

void HashTable::printIndex(ostream& ostrm)
{
    ostrm << "Hash Table Contains:" << endl;
    for (auto it = table.begin(); it != table.end(); ++it)
      ostrm << it->first << " : " << it->second << endl;
    ostrm << endl;
}

bool HashTable::isFound(string word)
{
    //create iterator
    unordered_map<string, WordInfo>::const_iterator got = table.find (word);

    //searches
    if (got == table.end())
        return false;
    else
        return true;
}

void HashTable::incrementFrequency(string word, string SHA1, int freq)
{
    table.find(word).setDocFreqPair(SHA1, freq);
}
