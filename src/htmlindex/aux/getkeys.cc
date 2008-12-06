#include "../htmlindex.h"

void getKeys()
{
    string
        line;
    Pattern
        pattern("([^:]+):<index\\s+(\\d+)\\s+(.*)>");
    unsigned
        filenameIndex = 0,
        nr = 0;

    while (getline(cin, line))
    {
        nr++;

        try
        {
            pattern.match(line);
        }
        catch (...)
        {
            cerr << "Invalid entry at line " << nr << ": `" << line << "'\n";
            returnValue = 1;
            continue;
        }

        Pattern::Position
            pos = pattern.position(3);

        if (pos.first == pos.second)
        {
            cerr << "Missing key at line " << nr << ": `" << line << "'\n";
            returnValue = 1;
            continue;
        }

        string
            filename = pattern[1],
            key = pattern[3];
        unsigned
            labelNr = atoi(pattern[2].c_str());

        if (filename != lastFilename)
        {
            filenameIndex = filenameVector.size();
            filenameVector.push_back(filename);
            lastFilename = filename;
            cerr << "File " << filename <<
                    " at " << filenameIndex << endl;
        }


    /*
        hash<string key, unsigned idx>
            indexHash
                contains the key and an idx in `index' where
                IndexEntry objects are stored.

        vector<IndexEntry>
                index;

        IndexEntry: contains the key (and for comparisons speedup the
            lowercase key, and vector of unsigned label numbers.

        First hash (and index) are filled.
    */

        hash_iterator
            it = indexHash.find(key);

        if (it != indexHash.end())           // key already available
        {
            //cerr << "duplicate key: " << key;
            indexVector[it->second].push_back(filenameIndex, labelNr);
        }
        else
        {                               // new key: add to the hashtable
            //cerr << "new key: " << key;
            indexHash.insert
            (
                //hash_map<string, unsigned, HashString>::value_type
                HashString<unsigned>::value_type
                (
                    key, indexVector.size()
                )
            );
            //cerr << "...";
                                        // and add to the `index' vector
            indexVector.push_back(IndexEntry(key,
                                  filenameIndex, labelNr));
        }
        //cerr << " inserted\n";
    }
}
