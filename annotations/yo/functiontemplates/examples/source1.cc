    #include <iostream>
    #include "add.h"
    #include "pointerunion.h"

    void fun()
    {
        PointerUnion pu = { add };

        std::cout << pu.vp << '\n';
    }
