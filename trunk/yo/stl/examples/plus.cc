    #include <iostream>
    #include <string>
    #include <functional>
    using namespace std;

    int main(int argc, char **argv)
    {
        plus<size_t> uAdd;              // function object to add size_ts

        cout << "3 + 5 = " << uAdd(3, 5) << '\n';

        plus<string> sAdd;              // function object to add strings

        cout << "argv[0] + argv[1] = " << sAdd(argv[0], argv[1]) << '\n';
    }
    /*
        Output when called as: a.out going

        3 + 5 = 8
        argv[0] + argv[1] = a.outgoing
    */
