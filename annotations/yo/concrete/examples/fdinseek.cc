    #include "fdinseek.h"
    #include <string>
    #include <iostream>
    #include <istream>
    #include <iomanip>
    using namespace std;

    int main()
    {
        IFdSeek fds(0);
        istream is(&fds);
        string  s;

        while (true)
        {
            if (!getline(is, s))
                break;

            streampos pos = is.tellg();

            cout << setw(5) << pos << ": `" << s << "'\n";

            if (!getline(is, s))
                break;

            streampos pos2 = is.tellg();

            cout << setw(5) << pos2 << ": `" << s << "'\n";

            if (!is.seekg(pos))
            {
                cout << "Seek failed\n";
                break;
            }
        }
    }
