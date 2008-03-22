    #include <iostream>
    #include "add.h"
    #include "pointerunion.h"

    void fun();

    int main()
    {
        PointerUnion pu = { add };

        fun();
        std::cout << pu.vp << std::endl;
    }
