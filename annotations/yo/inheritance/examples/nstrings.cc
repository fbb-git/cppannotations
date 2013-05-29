#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

string *nStrings(size_t size, char const *fname)
{
    static ifstream in;

    struct Xstr: public string
    {
        Xstr()
        :
            string(nextLine())
        {}
        static char const *nextLine()
        {
            static string line;

            getline(in, line);
            return line.c_str();
        }
    };
    in.open(fname);
    string *sp = new Xstr[size];
    in.close();

    return sp;
}

int main()
{
    string *sp = nStrings(10, "nstrings.cc");
    copy(sp, sp + 10, ostream_iterator<string>(cout, "\n"));
}
