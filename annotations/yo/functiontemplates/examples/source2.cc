    #include <iostream>
    #include "pointerunion.h"

    template<typename Type>
    Type add(Type const &, Type const &);

    void fun()
    {
        PointerUnion pu = { add };

        std::cout << pu.vp << '\n';
    }
