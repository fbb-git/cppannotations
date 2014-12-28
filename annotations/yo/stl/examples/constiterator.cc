    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    int main(int argc, char **argv)
    {
        vector<string> const args(argv, argv + argc);

        for
        (
            vector<string>::const_iterator iter = args.begin();
                iter != args.end();
                    ++iter
        )
            cout << *iter << " ";
        cout << '\n';

        for
        (
            vector<string>::const_reverse_iterator iter = args.rbegin();
                iter != args.rend();
                    ++iter
        )
            cout << *iter << " ";
        cout << '\n';
    }
