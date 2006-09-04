    #include <iostream>
    #include "sumvector.h"
    #include "pointerunion.h"

    void fun()
    {
        PointerUnion
            pu = { sumVector };

        std::cout << pu.vp << std::endl;
    }
