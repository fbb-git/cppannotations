    #include <iostream>
    #include <string>
    #include <functional>
    #include <algorithm>
    using namespace std;

    int main(int argc, char **argv)
    {
        sort(argv, argv + argc, greater_equal<string>());

        for (int idx = 0; idx < argc; ++idx)
            cout << argv[idx] << " ";
        cout << '\n';

        sort(argv, argv + argc, less<string>());

        for (int idx = 0; idx < argc; ++idx)
            cout << argv[idx] << " ";
        cout << '\n';
    }
