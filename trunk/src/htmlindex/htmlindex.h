//                              htmlindex.h

#ifndef _H_htmlindex_
#define _H_htmlindex_

#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <bobcat/hash>
#include <bobcat/arg>
#include <bobcat/pattern>

using namespace FBB;
using namespace std;

void usage(string const &basename);
void getKeys();
void head();
void display(unsigned idx);
void tail();

extern char
    indexSection,
    version[],
    year[];

extern int
    returnValue;

extern string
    lastFilename;

extern vector<string>
    filenameVector;

extern HashString<unsigned> // hash_map<string, unsigned, HashString>
    indexHash;

typedef HashString<unsigned>::iterator
    // hash_map<string, unsigned, HashString>::iterator
    hash_iterator;

class IndexEntry
{
    public:
        IndexEntry(string const &key,
                    unsigned filenameIndex, unsigned labelNr);
        void push_back(unsigned filenameIndex, unsigned labelNr)
        {
            labels.push_back(pair<unsigned, unsigned>(filenameIndex, labelNr));
        }
        bool operator<(IndexEntry const &other) const;

        string const &getKey()
        {
            return key;
        }
        char firstChar()
        {
            return uppercaseKey[0];
        }
        void showRefs();
    private:
        string
            uppercaseKey,
            key;
        vector<pair<unsigned, unsigned> >
            labels;
};

extern vector<IndexEntry>
    indexVector;

#endif
