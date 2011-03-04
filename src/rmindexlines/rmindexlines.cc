#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line1;
    string line2;

    getline(cin, line1);                    // initialization: pick up line 1
                                            // which is never a \n
    while (getline(cin, line2))
    {
        cout << line1;

        if (line2.find("<index") == 0)      // found an <index line
            getline(cin, line1);            // then get the next line
        else
        {
            cout << '\n';
            line1 = line2;
        }
    }
    cout << line1 << '\n';
}
