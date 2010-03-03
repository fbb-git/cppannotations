    #include <iostream>
    #include <fstream>
    #include <string>
    using namespace std;

    void err(char const *msg);      // see earlier example
    void err(char const *msg, long value);

    void read(istream &index, istream &strings)
    {
        index.clear();
        strings.clear();

        // insert the body of the read() function of the earlier example
    }


    void write(ostream &index, ostream &strings)
    {
        index.clear();
        strings.clear();

        // insert the body of the write() function of the earlier example
    }

    int main()
    {
        ifstream index_in("index", ios::trunc | ios::in | ios::out);
        ifstream strings_in("strings", ios::trunc | ios::in | ios::out);
        ostream  index_out(index_in.rdbuf());
        ostream  strings_out(strings_in.rdbuf());

        cout << "enter `r <number>' to read line <number> or "
                                    "w <line>' to write a line\n"
                "or enter `q' to quit.\n";

        while (true)
        {
            cout << "r <nr>, w <line>, q ? ";       // show prompt

            string cmd;

            cin >> cmd;                             // read cmd

            if (cmd == "q")                         // process the cmd.
                return 0;

            if (cmd == "r")
                read(index_in, strings_in);
            else if (cmd == "w")
                write(index_out, strings_out);
            else
                cout << "Unknown command: " << cmd << '\n';
        }
    }
