    #include <iostream>

    template <typename T>
    class Base
    {
        public:
            void member()
            {
                std::cout << "This is Base<T>::member()\n";
            }
    };

    template <typename T>
    class Derived: public Base<T>
    {
        public:
            Derived()
            {
                member();
            }
    };
