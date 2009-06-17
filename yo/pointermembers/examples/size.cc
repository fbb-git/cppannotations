    #include <string>
    #include <iostream>

    class X
    {
        public:
            void fun();
            std::string d_str;
    };

    inline void X::fun()
    {
        std::cout << "hello\n";
    }

    using namespace std;

    int main()
    {
        cout <<
           "size of pointer to data-member:     " << sizeof(&X::d_str) << "\n"
           "size of pointer to member function: " << sizeof(&X::fun) << "\n"
           "size of pointer to non-member data: " << sizeof(char *) << "\n"
           "size of pointer to free function:   " << sizeof(&printf) << endl;
    }

    /*
        generated output:

        size of pointer to data-member:     4
        size of pointer to member function: 8
        size of pointer to non-member data: 4
        size of pointer to free function:   4
    */
