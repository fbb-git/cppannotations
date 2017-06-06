#include <iostream>
    class Data
    {
        public:
            Data();
            Data(int one);
            Data(int one, int two);

            void display();
    };

    void fun()
    {
        int b = 18;

        {
            Data(b);
            std::cout << b;
        }
    }
