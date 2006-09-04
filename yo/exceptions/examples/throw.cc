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
                cout << "Object constructor of " << d_name << "\n";
            }
            Object(Object const &other)
            :
                d_name(other.d_name + " (copy)")
            {
                cout << "Copy constructor for " << d_name << "\n";
            }
            ~Object()
            {
                cout << "Object destructor of " << d_name << "\n";
            }
            void fun()
            {
                Object toThrow("'local object'");

                cout << "Object fun() of " << d_name << "\n";
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
    /*
        Generated output:
Object constructor of 'main object'
Object constructor of 'local object'
Object fun() of 'main object'
Copy constructor for 'local object' (copy)
Object destructor of 'local object'
Copy constructor for 'local object' (copy) (copy)
Caught exception
Hello by 'local object' (copy) (copy)
Object destructor of 'local object' (copy) (copy)
Object destructor of 'local object' (copy)
Object destructor of 'main object'
    */
