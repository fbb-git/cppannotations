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
            std::cout << "fun called for " << x << std::endl;
        }
    }

    int main()
    {
        fun(FBB::first);    // Koenig lookup: no namespace
                            // for fun()
    }
    /*
        generated output:
    fun called for 0
    */
