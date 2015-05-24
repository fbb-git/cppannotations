#include <string>
#include <iostream>
#include <regex>
#include <iterator>

using namespace std;

int main()
{
//start
    regex re("([[:alpha:]]+)\\s+(\\d+)");  // letters blanks digits

    string target("this value 1024 is interesting");

    regex_replace(ostream_iterator<char>(cout, ""), target.begin(),
                    target.end(), re, string("$2"));
//=
    cout << '\n';
}




