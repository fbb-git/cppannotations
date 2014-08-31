#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
    string line;
    bool empty = true;

    ifstream in(argv[1]);

    while (getline(in, line))          // find the first non-empty line
    {
        if (line.find_first_not_of(" \t") != string::npos)  // non-empty line
        {
            empty = false;              // avoid doubly checking `line'
            break;
        }
    }

    if (empty)                          // nothing but emptyness...
        return 0;

    size_t indent = 0;

    if (argc > 2)
        indent = stoul(argv[2]);

    size_t lineNr = 0;
    size_t nEmpty = 0;                  // counts empty lines

    cout << "\n"
            "verb(" << setw(indent) << ' ' << 
                setw(2) << ++lineNr << ' ' << line; // show the 1st line
    
    while (getline(in, line))          // read the rest of the file
    {
        if (line.find_first_not_of(" \t") == string::npos)  // empty line
        {
            ++nEmpty;                   // count it
            continue;                   // proceed with the next line
        }

        if (lineNr != 0)
            cout << '\n';

        for (size_t nr = 0; nr != nEmpty; ++nr) // 'for': # iterations known
            cout << setw(indent) << ' ' << setw(2) << ++lineNr << '\n';
        nEmpty = 0;                     // reset the counter

        cout << setw(indent) << ' ' << 
                setw(2) << ++lineNr << ' ' << line; // show the line
    }
    cout << ")\n";
}







