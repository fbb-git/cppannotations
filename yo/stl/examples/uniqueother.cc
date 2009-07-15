    #include <iostream>
    #include <memory>
    #include <string>

    using namespace std;

    int main()
    {
        unique_ptr<string> hello1(new string("Hello world"));
        unique_ptr<string> hello2(move(hello1));
        unique_ptr<string> hello3;

        hello3 = move(hello2);
        cout << // *hello1 << endl <<   // would segfault
                // *hello2 << endl <<   // same
                *hello3 << endl;
    }
    /*
        Produced output:

        Hello world
    */
