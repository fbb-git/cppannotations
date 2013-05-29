    #include <iostream>
    #include <string>
    #include <procbuf.h>

    int main()
    {
        procbuf
            pb;

        pb.open("ls -Fla", ios::in);

        istream
            ipb(&pb);

        string
            line,
            dirs;

        cout << "Files:\n";
        while (getline(ipb, line))
        {
            if (line[0] == 'd')
                dirs += line + '\n';
            else
                cout << line << '\n';
        }
        cout << "Directories:\n" << dirs;
    }
