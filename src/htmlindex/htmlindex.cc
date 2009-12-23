/*
                              htmlindex.cc
*/

#include "htmlindex.h"

HashString<unsigned>
    indexHash;
vector<IndexEntry>
    indexVector;
vector<string>
    filenameVector;
string
    lastFilename;
char
    indexSection = 'A' - 1;
int
    returnValue = 0;

int main(int argc, char **argv)
{
    Arg::initialize("", argc, argv);

    Arg &arg(Arg::instance());

    if (isatty(STDIN_FILENO))
        usage(arg.basename());

    getKeys();

    sort(indexVector.begin(), indexVector.end());

    head();

    unsigned
        n = indexVector.size(),
        halfway = (n + 1) / 2;

    cout << "<td valign=top>\n" <<
        "<table>\n";                    // left column as a table

    for (unsigned idx = 0; idx < halfway; idx++)    // print left column
    {
        cout << "<tr>\n";
        display(idx);
        cout << "</tr>\n";
    }

    cout << "</table>\n" <<
            "</td>\n" <<                    // left column done
            "<td valign=top>\n" <<
            "<table>\n";                    // right column as a table

    for (unsigned idx = halfway; idx < n; idx++)    // print right column
    {
        cout << "<tr>\n";
        display(idx);
        cout << "</tr>\n";
    }

    cout << "</table>\n" <<
            "</td>\n";                  // right column done


    tail();

    return returnValue;
}
