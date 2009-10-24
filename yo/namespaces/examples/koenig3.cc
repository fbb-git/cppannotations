    #include <iostream>

    namespace ES
    {
        enum Value        // defines ES::Value
        {
            FIRST
        };
    }

    namespace FBB
    {
        enum Value        // defines FBB::Value
        {
            FIRST
        };

        void fun(Value x, ES::Value y)
        {
            std::cout << "FBB::fun() called\n";
        }
    }

    namespace ES
    {
        void fun(FBB::Value x, Value y)
        {
            std::cout << "ES::fun() called\n";
        }
    }

    int main()
    {
        //  fun(FBB::FIRST, ES::FIRST); ambiguity: resolved by 
        //                              explicitly mentioning 
        //                              the namespace
        ES::fun(FBB::FIRST, ES::FIRST);
    }
    /*
        generated output:
    ES::fun() called
    */
