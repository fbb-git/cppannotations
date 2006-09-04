#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
using namespace std;

bool silent;

namespace std
{
    istream &operator>>(istream &in, string &line)
    {
        return getline(in, line);
    }
}

class NonEmpty
{
    public:
        bool operator()(string const &str) const
        {
            return str.find_first_not_of(" \t") != string::npos;
        }
};

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
            string::size_type idx = str.find_last_not_of(" \t");
            if (idx == string::npos)        // no non-ws char: print empty line
                d_out << endl;
            else if (idx + 1 == str.length())   // no trailing ws
                d_out << str << endl;
            else                                // \ requires 1 space
                d_out << str.substr(0, idx + 1) << endl;
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

    copy(istream_iterator<string>(*ip), istream_iterator<string>(),
            back_inserter(vs));

    vector<string>::reverse_iterator it = find_if(vs.rbegin(), vs.rend(),
                NonEmpty());

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

    for_each(vs.begin(), vector<string>::iterator(&*(it - 1)), Trimmer(*op));
}

int main(int argc, char **argv)
{
    if (argc == 1)
        trim();
    else
    {
        if (argc > 1)
            silent = string("-q") == argv[1];

        for (int idx = 1 + silent; idx < argc; idx++)
        trim(argv[idx]);
    }
}
