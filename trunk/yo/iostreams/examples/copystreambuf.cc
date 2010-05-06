    #include <iostream>
    using namespace std;

    int main()
    {
        cin.ignore(80, '\n');   // skip the first line and...
        cout << cin.rdbuf();    // copy the rest through the streambuf *
    }
