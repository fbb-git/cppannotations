    #include <fstream>
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        fstream rw("fname", ios::out | ios::in);
        if (!rw)
        {
            rw.clear();
            rw.open("fname", ios::out | ios::trunc | ios::in);
        }
        if (!rw)
        {
            cerr << "Opening `fname' failed miserably" << endl;
            return 1;
        }

        cerr << rw.tellp() << endl;

        rw << "Hello world" << endl;
        rw.seekg(0);

        string s;
        getline(rw, s);

        cout << "Read: " << s << endl;
    }
