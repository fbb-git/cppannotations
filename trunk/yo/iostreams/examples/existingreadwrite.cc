    #include <fstream>
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        fstream rw("fname", ios::out | ios::in);

        if (!rw)            // file didn't exist yet
        {
            rw.clear();     // try again, creating it using ios::trunc
            rw.open("fname", ios::out | ios::trunc | ios::in);
        }

        if (!rw)            // can't even create it: bail out
        {
            cerr << "Opening `fname' failed miserably" << '\n';
            return 1;
        }

        cerr << "We're at: " << rw.tellp() << '\n';

                            // write something
        rw << "Hello world" << '\n';

        rw.seekg(0);        // go back and read what's written

        string s;
        getline(rw, s);

        cout << "Read: " << s << '\n';
    }
