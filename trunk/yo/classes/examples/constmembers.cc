    #include <iostream>
    using namespace std;

    class Members
    {
        public:
            Members();
            void member();
            void member() const;
    };

    Members::Members()
    {}
    void Members::member()
    {
        cout << "non const member\n";
    }
    void Members::member() const
    {
        cout << "const member\n";
    }

    int main()
    {
        Members const constObject;
        Members       nonConstObject;

        constObject.member();
        nonConstObject.member();
    }
    /*
            Generated output:

        const member
        non const member
    */
