    #include <iostream>
    #include <setjmp.h>
    #include <cstdlib>

    using namespace std;

    jmp_buf jmpBuf;

    class Inner
    {
        public:
            Inner();
            ~Inner();
            void fun();
    };

    Inner::Inner()
    {
        cout << "Inner constructor\n";
    }
    void Inner::fun()
    {
        cout << "Inner fun\n";
        longjmp(jmpBuf, 0);
    }
    Inner::~Inner()
    {
        cout << "Inner destructor\n";
    }

    class Outer
    {
        public:
            Outer();
            ~Outer();
            void fun();
    };

    Outer::Outer()
    {
        cout << "Outer constructor\n";
    }
    Outer::~Outer()
    {
        cout << "Outer destructor\n";
    }
    void Outer::fun()
    {
        Inner in;
        cout << "Outer fun\n";
        in.fun();
    }

    int main()
    {
        Outer out;

        if (setjmp(jmpBuf) != 0)
            return 1;

        out.fun();
    }
    /*
        Generated output:
    Outer constructor
    Inner constructor
    Outer fun
    Inner fun
    Outer destructor
    */
