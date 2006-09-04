    #include <iostream>
    #include <string>
    using namespace std;

    class NoInsertion
    {
        public:
            operator string() const;
    };

    int main()
    {
        NoInsertion object;

        cout << object << endl;
    }
