    #include <string>
    #include <iostream>
    #include <istream>
    #include "fdout.h"
    using namespace std;

    int main(int argc)
    {
        ofdnstreambuf   fds(STDOUT_FILENO, 500);
        ostream         os(&fds);

        switch (argc)
        {
            case 1:
                os << "COPYING cin LINE BY LINE\n";
                for (string  s; getline(cin, s); )
                    os << s << endl;
            break;

            case 2:
                os << "COPYING cin BY EXTRACTING TO os.rdbuf()\n";

                cin >> os.rdbuf();      // Alternatively, use:  cin >> &fds;
            break;

            case 3:
                os << "COPYING cin BY INSERTING cin.rdbuf() into os\n";
                os << cin.rdbuf();
            break;
        }
    }
