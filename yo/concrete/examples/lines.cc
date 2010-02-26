#include "lines.h"
#include <iostream>

Lines::Lines(std::istream &in)
{
    std::string str;
    while (getline(in, str))
        d_line.push_back(str);
}

using namespace std;

int main()
{
    ifstream in("lines.cc");
    Lines lines(in);

    cout << lines[0] << '\n';
    lines[0] = "hello world";
    cout << lines[0] << '\n';
}
