    #include <iostream>
    #include <map>
    using namespace std;

    class MyClass
    {
        public:
            MyClass()
            {
                cout << "MyClass constructor\n";
            }
            MyClass(MyClass const &other)
            {
                cout << "MyClass copy constructor\n";
            }
            ~MyClass()
            {
                cout << "MyClass destructor\n";
            }
    };

    int main()
    {
        pair<string, MyClass> pairs[] =
        {
            pair<string, MyClass>("one", MyClass())
        };
        cout << "pairs constructed\n";

        map<string, MyClass> mapsm(&pairs[0], &pairs[1]);
        cout << "mapsm constructed\n";
    }
    /*
        Generated output:
    MyClass constructor
    MyClass copy constructor
    MyClass destructor
    pairs constructed
    MyClass copy constructor
    MyClass copy constructor
    MyClass destructor
    mapsm constructed
    MyClass destructor
    MyClass destructor
    */
