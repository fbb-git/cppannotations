#include "lines.h"
#include <iostream>

Lines::Lines(std::istream &in)
{
    std::string str;
    while (getline(in, str))
        d_line.push_back(str);
}

using namespace std;

//MAIN
    int main()
    {
        ifstream in("lines.cc");
        Lines lines(in);
    
        string s = lines[0];        // rvalue use
        lines[0] = s;               // lvalue use
        cout << lines[0] << '\n';   // rvalue use
        lines[0] = "hello world";   // lvalue use
        cout << lines[0] << '\n';   // rvalue use
    }
//=
