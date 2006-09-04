    #include <string>

    using namespace std;

    int main()
    {
        string stringOne("Hello World");  // using plain ascii-Z
        string stringTwo(stringOne);      // using another string object
        string stringThree;               // implicit initialization to "". Do
                                          // not use the form `stringThree()'
        return 0;
    }
