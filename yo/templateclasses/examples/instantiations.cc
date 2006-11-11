    #include <iostream>

    template <typename Type>
    class Demo
    {
        Type d_data;

        public:
            Demo();
            Demo(Type const &value);

            void member1();
            void member2(Type const &value);
    };

    template <typename Type>
    Demo<Type>::Demo()
    :
        d_data(Type())
    {}

    template <typename Type>
    void Demo<Type>::member1()
    {
        d_data += d_data;
    }

    // the following members are commented out before compiling
    // the second program

    template <typename Type>
    Demo<Type>::Demo(Type const &value)
    :
        d_data(value)
    {}

    template <typename Type>
    void Demo<Type>::member2(Type const &value)
    {
        d_data += value;
    }

    int main()
    {
        Demo<int> demo;
        demo.member1();
    }

