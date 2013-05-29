    #include <algorithm>
    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string line;

        while (getline(cin, line))
        {
            size_t    size = line.size();
            char        copy[size + 1];

            cout << "line: " << line << '\n' <<
                    "reversed: ";
            reverse_copy(line.begin(), line.end(), copy);
            copy[size] = 0;     // 0 is not part of the reversed
                                // line !
            cout << copy << '\n';
        }
    }
