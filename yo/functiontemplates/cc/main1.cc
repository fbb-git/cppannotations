    #include <iostream>
    #include "sumvector.h"
    #include "pointerunion.h"

    void fun();

    int main()
    {
        fun();

        PointerUnion
            pu = { sumVector };

        std::cout << pu.vp << std::endl;

        return 0;
    }
    /*
        Generated output (actual pointer values may be different):

        0x8048710
        0x8048710
    */
