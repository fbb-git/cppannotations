    #include <iostream>

    template <typename Type>
    class Demo
    {
        Type d_data;

        public:
            Demo()
            :
                d_data(Type())
            {}
            void member1()
            {
                d_data += d_data;
            }

            // the following members are commented out before compiling
            // the second program

            Demo(Type const &value)
            :
                d_data(value)
            {}
            void member2(Type const &value)
            {
                d_data += value;
            }
    };

    int main()
    {
        Demo<int> demo;
        demo.member1();
    }
