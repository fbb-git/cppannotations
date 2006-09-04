    #include <pfstream.h>
    #include <string>

    int main()
    {
        opfstream
            opb("|sort -f");
        string
            line;

        while (getline(cin, line))
        {
            int
                pos;
            if
            (
                line.length() == 0 ||
                    (pos = line.find_first_not_of(" \t")) != string::npos &&
                    line[pos] == '#'
            )
                continue;

            opb << line << endl;
        }
    }
