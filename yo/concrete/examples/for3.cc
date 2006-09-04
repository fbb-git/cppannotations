    #include <iostream>
    #include <vector>
    #include <iterator>
    #include "foreach.h"
    using namespace std;

    class StringVector: public vector<string>
    {
        public:
            StringVector(char **begin, char **end)
            :
                vector<string>(begin, end)
            {}
            void operator()(string const &str)
            {
                cout << str << " ";
            }
    };

    int main(int argc, char **argv)
    {
        StringVector vs(argv, argv + argc);

        ForEach(vs.begin(), vs.end(), vs);
        cout << endl;
    }
    /*
        Output generated when running a.out alpha bravo charley

        a.out alpha bravo charley
    */
