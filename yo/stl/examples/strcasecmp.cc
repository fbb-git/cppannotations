    #include <iostream>
    #include <string>
    #include <cstring>
    #include <algorithm>
    using namespace std;

    class CaseInsensitive
    {
        public:
            bool operator()(string const &left, string const &right) const
            {
                return strcasecmp(left.c_str(), right.c_str()) < 0;
            }
    };
    int main(int argc, char **argv)
    {
        sort(argv, argv + argc, CaseInsensitive());
        for (int idx = 0; idx < argc; ++idx)
            cout << argv[idx] << " ";
        cout << '\n';
    }
