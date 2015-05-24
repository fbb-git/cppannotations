#include <string>
#include <iostream>
#include <regex>
#include <iterator>

using namespace std;

int main()
{
//start
    regex re("([[:alpha:]]+)\\s+(\\d+)");  // letters blanks digits

    smatch results;
    string target("this value 1024 is interesting");

    if (not regex_search(target, results, re))
        return 1;
//=
    results.format(ostream_iterator<char>(cout, ""), string("$2"));
    cout << '\n';

    string reverse(results.format("$2 and $1"));
    cout << reverse << '\n';
}
