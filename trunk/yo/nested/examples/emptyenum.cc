    #include <iostream>

    enum EmptyEnum
    {};

    using namespace std;

    int main()
    try
    {
        throw EmptyEnum();
    }
    catch (EmptyEnum)
    {
        cout << "Caught empty enum\n";
    }
    /*
        Generated output:

        Caught empty enum
    */
