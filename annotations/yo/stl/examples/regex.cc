#include <string>
#include <iostream>
#include <regex>

using namespace std;


int main()
{
    cout << "Empty pattern to quit, empty target to specify new pattern\n";

    while (true)
    {
        string pat;

        cout << "Pattern: ";
        getline(cin, pat);
        if (pat.empty())
            break;

        while (true)
        {
            cout << "Target: ";
            string target;
            getline(cin, target);
            if (target.empty())
                break;

            regex re(pat);
            smatch sm;

            cout << "Before the match: empty = " << sm.empty() << '\n';

            regex_search(target, sm, re);
            cout << sm.size() << '\n';

            for (size_t idx = 0; idx != sm.size(); ++idx)
                cout << sm[idx] << '\n';

            cout << "After the match: empty = " << sm.empty() << '\n';

            for (auto &m: sm)
                cout << "sub match: " << m << '\n';

            while (true)
            {
                cout << "Which match position (empty for none)? ";
                string str;
                getline(cin, str);
                if (str.empty())
                    break;
                cout << "nr " << str << ": " << sm.str(stoul(str)) <<
                        '\n';
            }
        }
    }
}
