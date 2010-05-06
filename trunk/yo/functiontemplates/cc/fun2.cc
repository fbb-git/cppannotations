    #include <iostream>
    #include "sumvector.h"
    #include "pointerunion.h"

    template<typename T>
    T sumVector(T *tp, size_t n);

    void fun()
    {
        PointerUnion
            pu = { sumVector };

        std::cout << pu.vp << '\n';
    }
