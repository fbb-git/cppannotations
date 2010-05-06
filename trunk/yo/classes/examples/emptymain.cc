    #include <iostream>
    using namespace std;

    class Demo
    {
        public:
            Demo();
    };

    Demo::Demo()
    {
        cout << "Demo constructor called\n";
    }

    Demo d;

    int main()
    {}

    /*
        Generated output:
    Demo constructor called
    */
