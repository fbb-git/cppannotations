    #include <iostream>
    #include <string>
    #include <cassert>

    using namespace std;

    int main(int argc, char **argv)
    {
        assert(argc == 3 &&
            "Usage: <searchstring> <replacestring> to process stdin");

        string line;
        string search(argv[1]);
        string replace(argv[2]);

        assert(search != replace);

        while (getline(cin, line))
        {
            string::size_type idx = 0;
            while (true)
            {
                idx = line.find(search, idx); // find(): another string member
                                              //         see `searching' below
                if (idx == string::npos)
                    break;

                line.replace(idx, search.size(), replace);
                idx += replace.length();     // don't change the replacement
            }
            cout << line << endl;
        }
        return 0;
    }
