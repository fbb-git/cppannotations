    /*
                                  table.cc
    */

    #include <fstream>
    #include <iostream>
    #include <string>
    #include <iterator>
    #include <sstream>

    #include "tablesupport/tablesupport.h"
    #include "table/table.h"

    using namespace std;
    using namespace FBB;

    int main(int argc, char **argv)
    {
        size_t nCols = 5;
        if (argc > 1)
        {
            istringstream iss(argv[1]);
            iss >> nCols;
        }

        istream_iterator<string>   iter(cin);   // first iterator isn't const

        Table<istream_iterator<string> >
            table(iter, istream_iterator<string>(), nCols,
                  argc == 2 ? TableType::VERTICAL : TableType::HORIZONTAL);

        cout << table << '\n';
        return 0;
    }
    /*
        Example of generated output:
        After: echo a b c d e f g h i j | demo 3
            a e i
            b f j
            c g
            d h
        After: echo a b c d e f g h i j | demo 3 h
            a b c
            d e f
            g h i
            j
    */
