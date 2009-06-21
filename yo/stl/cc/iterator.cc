    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    int main(int argc, char **argv)
    {
        vector<string> args(argv, argv + argc);

        for (auto iter = args.begin(); iter != args.end(); ++iter)
            cout << *iter << " ";
        cout << endl;

        for (auto iter = args.rbegin(); iter != args.rend(); ++iter)
            cout << *iter << " ";
        cout << endl;

        return 0;
    }
