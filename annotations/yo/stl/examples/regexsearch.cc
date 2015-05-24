#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Enter a pattern or plain Enter to stop: ";

        string pattern;
        if (not getline(cin, pattern) or pattern.empty())
            break;

        regex re(pattern);
        while (true)
        {
            cout << "Enter a target text for `" << pattern << "'\n"
                    "(plain Enter for the next pattern): ";

            string text;
            if (not getline(cin, text) or text.empty())
                break;

            smatch results;
            if (not regex_search(text, results, re))
                cout << "No match\n";
            else
            {
                cout << "Prefix: "  << results.prefix() << "\n"
                        "Match:  "  << results.str()    << "\n"
                        "Suffix: "  << results.suffix() << "\n";
                for (size_t idx = 1; idx != results.size(); ++idx)
                    cout << "Match " << idx << " at offset " <<
                                results.position(idx) << ": " <<
                                results.str(idx) << '\n';
            }
        }
    }
}
