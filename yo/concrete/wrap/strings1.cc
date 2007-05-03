    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    #include "support.h"

    class Strings
    {
        std::vector<std::string> d_vs;

        public:
            void uppercase(std::ostream &out, char const *letters);
    };

    void Strings::uppercase(std::ostream &out, char const *letters)
    {
        for_each(d_vs.begin(), d_vs.end(), Support(out, letters));
    }

    using namespace std;

    int main(int argc, char **argv)
    {
        Strings s;

        s.uppercase(cout, argv[1]);
    }




