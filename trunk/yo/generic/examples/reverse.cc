    #include <algorithm>
    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string line;

        while (getline(cin, line))
        {
            reverse(line.begin(), line.end());
            cout << line << '\n';
        }
    }
