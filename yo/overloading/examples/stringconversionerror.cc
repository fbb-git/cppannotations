    #include <iostream>
    #include <string>
    using namespace std;

    struct Insertable
    {
        operator int() const
        {
            cout << "op int()\n";
        }
    };
    ostream &operator<<(ostream &out, Insertable const &ins)
    {
        return out << "insertion operator";
    }
    struct Convertor
    {
        operator Insertable() const
        {
            return Insertable();
        }
    };
    struct Text
    {
        operator int() const
        {
            return 1;
        }
    };
    struct Error
    {
        operator Text() const
        {
            return Text();
        }
    };

    int main()
    {
        Insertable insertable;
        cout << insertable << '\n';
        Convertor convertor;
        cout << convertor << '\n';
        Error error;
        cout << error << '\n';
    }






