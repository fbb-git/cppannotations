    #include <iostream>
    using namespace std;

//CLASSES
    class First
    {
        public:
            First()
            {
                cout << "First()\n";
            }
            First(int x);
    };
    class Second: public virtual First      // note: virtual
    {
        public:
            Second(int x)
            :
                First(x)
            {}
    };
    class Third: public Second
    {
        public:
            Third(int x)
            :
                Second(x)
            {}
    };
    int main()
    {
        Third third(3);     // displays `First()'
    }
//=
