    #include <iostream>
    #include <string>

    using namespace std;

    int main(int argc, char **argv)
    {
        if (argc != 3)
        {
            cerr << "Usage: <searchstring> <replacestring> to process "
                                                                  "stdin\n";
            return 1;
        }

        string search(argv[1]);
        string replace(argv[2]);

        if (search == replace)
        {
            cerr << "The replace and search texts should be different\n";
            return 1;
        }

        string line;
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
