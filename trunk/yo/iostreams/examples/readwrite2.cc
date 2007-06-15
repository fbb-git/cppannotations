    #include <iostream>
    #include <fstream>
    #include <string>
    using namespace std;

    void err(char const *msg)
    {
        cout << msg << endl;
        return;
    }

    void err(char const *msg, long value)
    {
        cout << msg << value << endl;
        return;
    }

    void read(istream &index, istream &strings)
    {
        int idx;

        if (!(cin >> idx))                          // read index
            return err("line number expected");

        index.seekg(idx * sizeof(long));            // go to index-offset

        long offset;

        if
        (
            !index.read                             // read the line-offset
            (
                reinterpret_cast<char *>(&offset),
                sizeof(long)
            )
        )
            return err("no offset for line", idx);

        if (!strings.seekg(offset))                 // go to the line's offset
            return err("can't get string offet ", offset);

        string line;

        if (!getline(strings, line))                // read the line
            return err("no line at ", offset);

        cout << "Got line: " << line << endl;       // show the line
    }


    void write(ostream &index, ostream &strings)
    {
        string line;

        if (!getline(cin, line))                  // read the line
            return err("line missing");

        strings.seekp(0, ios::end);               // to strings
        index.seekp(0, ios::end);                 // to index

        long offset = strings.tellp();

        if
        (
            !index.write                          // write the offset to index
            (
                reinterpret_cast<char *>(&offset),
                sizeof(long)
            )
        )
            err("Writing failed to index: ", offset);

        if (!(strings << line << endl))           // write the line itself
            err("Writing to `strings' failed");
                                                  // confirm writing the line
        cout << "Write at offset " << offset << " line: " << line << endl;
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
                cout << "Unknown command: " << cmd << endl;
        }
    }
