    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    #include "support.h"

    class Strings
    {
        std::vector<std::string> d_vs;

        public:
            void uppercase(std::ostream &out)
            {
                for_each(d_vs.begin(), d_vs.end(), Support(out));
            }
    };

    using namespace std;

    int main()
    {
        Strings s;

        s.uppercase(cout);
    }
