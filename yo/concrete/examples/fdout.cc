    #include <string>
    #include <iostream>
    #include <istream>
    #include "fdout.h"
    using namespace std;

    int main(int argc, char **argv)
    {
        OFdnStreambuf   fds(STDOUT_FILENO, 500);
        ostream         os(&fds);

        switch (argc)
        {
            case 1:
                for (string  s; getline(cin, s); )
                    os << s << '\n';
                os << "COPIED cin LINE BY LINE\n";
            break;

            case 2:
                cin >> os.rdbuf();      // Alternatively, use:  cin >> &fds;
                os << "COPIED cin BY EXTRACTING TO os.rdbuf()\n";
            break;

            case 3:
                os << cin.rdbuf();
                os << "COPIED cin BY INSERTING cin.rdbuf() into os\n";
            break;
        }
    }
