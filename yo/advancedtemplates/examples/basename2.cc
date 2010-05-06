    #include <iostream>

    template <typename T>
    class Base
    {
        public:
            virtual void member();
    };
    template <typename T>
    void Base<T>::member()
    {
        std::cout << "This is Base<T>::member()\n";
    }
    template <>
    void Base<int>::member()
    {
        std::cout << "This is the int-specialization\n";
    }
    template <typename T>
    class Derived: public Base<T>
    {
        public:
            Derived();
            virtual void member();
    };
    template <typename T>
    void Derived<T>::member()
    {
        std::cout << "This is Derived<T>::member()\n";
    }
    template <typename T>
    Derived<T>::Derived()
    {
        this->member();         // Using `this' implies using the
                                // type for which T was instantiated
        Derived<T>::member();   // Same: calls the Derived member
        Base<T>::member();      // Same: calls the Base member
        std::cout << "Derived<T>::Derived() completed\n";
    }

    int main()
    {
        Derived<double> d;
        Derived<int> i;
    }

    /*
        Generated output:
    This is Derived<T>::member()
    This is Derived<T>::member()
    This is Base<T>::member()
    Derived<T>::Derived() completed
    This is Derived<T>::member()
    This is Derived<T>::member()
    This is the int-specialization
    Derived<T>::Derived() completed
    */
