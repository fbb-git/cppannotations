    #include <iostream>

    namespace FBB
    {
        enum Value        // defines FBB::Value
        {
            FIRST
        };

        void fun(Value x)
        {
            std::cout << "FBB::fun() called for " << x << '\n';
        }
    }

    namespace ES
    {
        void fun(FBB::Value x)
        {
            std::cout << "ES::fun() called for " << x << '\n';
        }
    }

    int main()
    {
        fun(FBB::FIRST);    // No ambiguity: argument determines
                            // the namespace
    }
    /*
        generated output:
    FBB::fun() called for 0
    */
