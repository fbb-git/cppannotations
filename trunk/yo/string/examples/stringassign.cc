    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello World");
        string stringTwo;

        stringTwo = stringOne;      // assign stringOne to stringTwo
        stringTwo = "Hello world";  // assign a C-string to StringTwo

        return 0;
    }
