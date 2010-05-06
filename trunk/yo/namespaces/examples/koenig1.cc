    #include <iostream>

    namespace FBB
    {
        enum Value        // defines FBB::Value
        {
            FIRST
        };

        void fun(Value x)
        {
            std::cout << "fun called for " << x << '\n';
        }
    }

    int main()
    {
        fun(FBB::FIRST);    // Koenig lookup: no namespace
                            // for fun() specified
    }
    /*
        generated output:
    fun called for 0
    */
