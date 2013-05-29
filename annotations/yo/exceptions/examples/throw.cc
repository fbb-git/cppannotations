//PROG
    #include <iostream>
    #include <string>
    using namespace std;

    class Object
    {
        string d_name;

        public:
            Object(string name)
            :
                d_name(name)
            {
                cout << "Constructor of " << d_name << "\n";
            }
            Object(Object const &other)
            :
                d_name(other.d_name + " (copy)")
            {
                cout << "Copy constructor for " << d_name << "\n";
            }
            ~Object()
            {
                cout << "Destructor of " << d_name << "\n";
            }
            void fun()
            {
                Object toThrow("'local object'");
                cout << "Calling fun of " << d_name << "\n";
                throw toThrow;
            }
            void hello()
            {
                cout << "Hello by " << d_name << "\n";
            }
    };

    int main()
    {
        Object out("'main object'");
        try
        {
            out.fun();
        }
        catch (Object o)
        {
            cout << "Caught exception\n";
            o.hello();
        }
    }
//=
    /*
        Generated output:
Constructor of 'main object'
Constructor of 'local object'
Calling fun of 'main object'
Copy constructor for 'local object' (copy)
Destructor of 'local object'
Copy constructor for 'local object' (copy) (copy)
Caught exception
Hello by 'local object' (copy) (copy)
Destructor of 'local object' (copy) (copy)
Destructor of 'local object' (copy)
Destructor of 'main object'
    */
