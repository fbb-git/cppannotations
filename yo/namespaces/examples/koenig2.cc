    #include <iostream>

    namespace FBB
    {
        enum Value        // defines FBB::Value
        {
            first,
            second,
        };

        void fun(Value x)
        {
            std::cout << "FBB::fun() called for " << x << std::endl;
        }
    }

    namespace ES
    {
        void fun(FBB::Value x)
        {
            std::cout << "ES::fun() called for " << x << std::endl;
        }
    }

    int main()
    {
        fun(FBB::first);    // No ambiguity: argument determines
                            // the namespace
    }
    /*
        generated output:
    FBB::fun() called for 0
    */
