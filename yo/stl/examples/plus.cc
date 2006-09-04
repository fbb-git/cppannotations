    #include <iostream>
    #include <string>
    #include <functional>
    using namespace std;

    int main(int argc, char **argv)
    {
        plus<unsigned> uAdd;       // function object to add unsigneds

        cout << "3 + 5 = " << uAdd(3, 5) << endl;

        plus<string> sAdd;       // function object to add strings

        cout << "argv[0] + argv[1] = " << sAdd(argv[0], argv[1]) << endl;
    }
    /*
        Generated output with call: a.out going

        3 + 5 = 8
        argv[0] + argv[1] = a.outgoing
    */
