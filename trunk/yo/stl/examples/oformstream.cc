    #include "oformstream.h"

    using namespace std;

    int main()
    {
        oformstream of(cout.rdbuf());

        of << "'";

        of.form("%s %s", "hello", "world") << "'\n"
            << "======\n";
    }
    /* Generated output:
    'hello world'
    ======
    */
