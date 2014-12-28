#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    string label(argv[1]);
    string endlabel(label[1] == '/' ? "//=" : "/**/");
    ifstream input(argv[2]);

    string line;
    bool print = false;

    cout << "        verb(\n";
    while (getline(input, line))
    {
        istringstream istr(line);
        string word1;
        istr >> word1;

        if (word1 == label)
        {
            if (print)
                break;
            print = true;
            label = endlabel;
            continue;
        }
        if (print)
            cout << line << '\n';
    }
    cout << "        )\n";
    if (!print)
    {
        cerr << "verbinsert(" << argv[1] << ")(" << argv[2] << ")\n" <<
                "          label section not found\n";
        return 1;
    }
    if (label != endlabel)
    {
        cerr << "verbinsert(" << argv[1] << ")(" << argv[2] << ")\n" <<
                "          unterminated label section\n";
        return 1;
    }
}
