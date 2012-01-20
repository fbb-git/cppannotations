    #include <iostream>

    enum EmptyEnum
    {};

    int main()
    try
    {
        throw EmptyEnum();
    }
    catch (EmptyEnum)
    {
        std::cout << "Caught empty enum\n";
    }
