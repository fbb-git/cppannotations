    #include <iostream>

    template <typename T>
    class Base
    {
        public:
            void member();
    };

    template <typename T>
    void Base<T>::member()
    {
        std::cout << "This is Base<T>::member()\n";
    }

    template <typename T>
    class Derived: public Base<T>
    {
        public:
            Derived();
    };

    template <typename T>
    Derived<T>::Derived()
    {
        member();
    }
