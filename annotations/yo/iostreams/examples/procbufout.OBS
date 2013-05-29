    #include <iostream>
    #include <string>
    #include <procbuf.h>

    int main()
    {
        procbuf pb;

        pb.open("sort -f", ios::out);

        ostream opb(&pb);
        string line;

        while (getline(cin, line))
        {
            size_t pos;
            if
            (
                line.length() == 0 ||
                    (pos = line.find_first_not_of(" \t")) != string::npos &&
                    line[pos] == '#'
            )
                continue;

            opb << line << '\n';
        }
    }
