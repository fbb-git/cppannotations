    #include <iostream>

    class Throw
    {
        public:
            Throw(int value)
            try
            {
                throw value;
            }
            catch(...)
            {
                std::cout << "Throw's exception handled locally by Throw()\n";
                throw;
            }
    };

    class Composer
    {
        Throw d_t;
        public:
            Composer()
            try             // NOTE: try precedes initializer list
            :
                d_t(5)
            {}
            catch(...)
            {
                std::cout << "Composer() caught exception as well\n";
            }
    };

    int main()
    {
        Composer c;
    }


