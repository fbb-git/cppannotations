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

    template <>
    void Base<int>::member()
    {
        std::cout << "This is the int-specialization\n";
    }


    template <typename T>
    class Derived: public Base<T>
    {
        public:
            Derived()
            {
                this->member();
                Base<T>::member();
            }
    };


    int main()
    {
        Derived<double> d;
        Derived<int> i;
    }

    /*
        Generated output:
        This is Base<T>::member()
        This is Base<T>::member()
        This is the int-specialization
        This is the int-specialization
    */
