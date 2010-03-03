    #include <iostream>
    #include <string>
    using namespace std;

    class Test
    {
        public:
            Test(string const &name);   // constructor with an argument
    };

    Test::Test(string const &name)
    {
        cout << "Test object " << name << " created" << '\n';
    }

    Test globaltest("global");

    void func()
    {
        Test functest("func");
    }

    int main()
    {
        Test first("main first");
        func();
        Test second("main second");
    }
/*
    Generated output:
Test object global created
Test object main first created
Test object func created
Test object main second created
*/
