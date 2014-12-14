#include <string>
#include <iostream>
#include <regex>
#include <iterator>

using namespace std;

//code
int main()
{
    regex re("hi");
    smatch sm;

    if (not regex_search("just say ``hi, there''", sm, re))
        return 1;

    string fmt("fully matched: $&, beyond: $'");

    cout << "Producing a std::string: " << sm.format(fmt) << '\n';

    cout << "Using an ostream_iterator: ";
    *sm.format(ostream_iterator<char>(cout, ""), fmt) = '\n';

    string out(40, 'x');
    *sm.format(out.begin(), fmt) = ' ';
    cout << "Overwriting an existing std::string: " << out << '\n';
}
//=
