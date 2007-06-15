    #include <iostream>
    using namespace std;

    class X
    {
        public:
            X();
            void member();
            void member() const;
    };

    X::X()
    {}
    void X::member()
    {
        cout << "non const member\n";
    }
    void X::member() const
    {
        cout << "const member\n";
    }

    int main()
    {
        X const constObject;
        X       nonConstObject;

        constObject.member();
        nonConstObject.member();
    }
    /*
            Generated output:

        const member
        non const member
    */
