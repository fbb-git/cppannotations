#include <unistd.h>
#include <libgen.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>

#include "../../VERSION"

using namespace std;

bool silent;

struct StringLine: public std::string
{};

istream &operator>>(istream &in, StringLine &line)
{
    return getline(in, line);
}

class Trimmer
{
    ostream &d_out;

    public:
        Trimmer(ostream &out)
        :
            d_out(out)
        {}

        void operator()(string const &str) const
        {
                                            // find last non ws
            size_t idx = str.find_last_not_of(" \t");

            if (idx == string::npos)        // no non-ws char: print empty line
                d_out << '\n';
            else if (idx + 1 == str.length())   // no trailing ws
                d_out << str << '\n';
            else                                // \ requires 1 space
                d_out << str.substr(0, idx + 1) << '\n';
        }
};

void trim(char const *name = 0)
{
    ifstream in;
    istream *ip;

    vector<string> vs;

    if (!name)
        ip = &cin;
    else
    {
        if (!silent)
            cout << "trimming `" << name << "'\n";
        in.open(name);
        if (!in)
        {
            cout << "no such file `" << name << "': skipped.\n";
            return;
        }
        ip = &in;
    }

    copy(istream_iterator<StringLine>(*ip), istream_iterator<StringLine>(),
            back_inserter(vs));

    vector<string>::reverse_iterator it = 
                find_if(vs.rbegin(), vs.rend(),
                    [&](string const &str)
                    {
                        return str.find_first_not_of(" \t") != string::npos;
                    }
                );

    ofstream out;
    ostream *op;

    if (!name)
        op = &cout;
    else
    {
        in.close();
        out.open(name);
        op = &out;
    }

    for_each(vs.begin(), vector<string>::iterator(&*(it - 1)), 
                                                            Trimmer{ *op });
}

char const info[] = R"( [-q] [file(s)]
Where:
    -q:         quiet (optional), suppress informative messages
    file(s):    zero or more files to process: trailing blanks at the end
                of lines are removed. 
                When no files are specified, the file to process is read
                from the redirected standard input stream.
)";

char const header[] = R"( by Frank B. Brokken (f.b.brokken@rug.nl)

Trailing blanks trimmer V )" VERSION R"(
Copyright (c) GPL )" YEARS R"(. NO WAARANTY.

Usage: )";

int main(int argc, char **argv)
{
    if (isatty(STDIN_FILENO) and argc == 1)
    {
        string base = basename(argv[0]);

        cout << base << header <<  base << info << '\n';
        return 0;
    }

    if (argc == 1)
        trim();
    else
    {
        if (argc > 1)
            silent = string("-q") == argv[1];

        for (size_t idx = 1 + silent; idx != size_t(argc); ++idx)
            trim(argv[idx]);
    }
}
