    #include <iostream>
    #include <memory>
    #include <string>
    using namespace std;

    int main()
    {
        auto_ptr<string> hello1(new string("Hello world"));
        auto_ptr<string> hello2(hello1);
        auto_ptr<string> hello3;

        hello3 = hello2;
        cout << *hello1 << endl <<
                *hello2 << endl <<
                *hello3 << endl;
    }
    /*
        Produced output:

        Segmentation fault
    */
