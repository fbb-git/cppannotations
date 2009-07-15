        #include <iostream>

        struct Cons
        {
            Cons()
            {
                std::cout << "Cons called\n";
            }
        };

        void called(char const *time)
        {
            std::cout << time << "time called() activated\n";
            static Cons cons;
        }

        int main()
        {
            std::cout << "Pre-1\n";
            called("first");
            called("second");
            std::cout << "Pre-2\n";
            Cons cons;
        }
    /*
        Generated output:

                Pre-1
                firsttime called() activated
                Cons called
                secondtime called() activated
                Pre-2
                Cons called
    */
