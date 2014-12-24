#include <string>
#include <iostream>
#include <regex>
#include <iterator>

using namespace std;

//code
bool modify(string const &match);
size_t replace(string &target, string::iterator begin, string match);

int main()
{
    string target("... oh, when the Saints, ...");

    regex re("\\w+");
    smatch match;
    size_t offset = 0;
    while (true)
    {
        auto begin = target.begin() + offset;
        if (not regex_search(string::const_iterator(begin),
                             target.cend(), match, re))
            break;

        size_t pos = match.position(0);

        offset += pos +
                modify(match[0]) ?
                    replace(target, begin + pos,  match[0])
                        :
                    match.length(0);
    }
    cout << "new text: " << target << '\n';
}
//=
