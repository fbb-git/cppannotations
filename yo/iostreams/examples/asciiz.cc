    #include <iostream>
    #include <fstream>
    using namespace std;

    int main()
    {                                       // r/w the file
        fstream f("hello", ios::in | ios::out | ios::trunc);

        f.write("hello", 6);                // write 2 ascii-z strings
        f.write("hello", 6);

        f.seekg(0, ios::beg);               // reset to begin of file

        char buffer[100];                   // or: char *buffer = new char[100]
        char c;
                                            // read the first `hello'
        cout << f.get(buffer, sizeof(buffer), 0).tellg() << endl;;
        f >> c;                             // read the ascii-z delim

                                            // and read the second `hello'
        cout << f.get(buffer + 6, sizeof(buffer) - 6, 0).tellg() << endl;

        buffer[5] = ' ';                    // change asciiz to ' '
        cout << buffer << endl;             // show 2 times `hello'
    }
    /*
        Generated output:
    5
    11
    hello hello
    */
