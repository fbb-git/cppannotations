    namespace FBB
    {
        struct Value
        {};

        void fun(int x);
        void gun(Value x);
    }

    namespace ES
    {
        void fun(int x)
        {
            fun(x);
        }
        void gun(FBB::Value x)
        {
            gun(x);
        }
    }
