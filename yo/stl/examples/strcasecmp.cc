    #include <iostream>
    #include <string>
    #include <algorithm>

    using namespace std;

    class case_less
    {
        public:
            bool operator()(string const &left, string const &right) const
            {
                return strcasecmp(left.c_str(), right.c_str()) < 0;
            }
    };

    int main(int argc, char **argv)
    {
        sort(argv, argv + argc, case_less());
        for (int idx = 0; idx < argc; ++idx)
            cout << argv[idx] << " ";
        cout << endl;
    }
