    #include <iostream>

    namespace ES
    {
        enum Value        // defines ES::Value
        {
            first,
            second,
        };
    }

    namespace FBB
    {
        enum Value        // defines FBB::Value
        {
            first,
            second,
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
        /*
            fun(FBB::first, ES::first); // ambiguity: must be resolved
                                        // by explicitly mentioning
                                        // the namespace
        */
        ES::fun(FBB::first, ES::first);
    }
    /*
        generated output:
    ES::fun() called
    */
