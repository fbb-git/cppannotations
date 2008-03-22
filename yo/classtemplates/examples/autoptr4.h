    #include <iostream>
    #include <vector>
    #include "autoptr.h"

    namespace FBB
    {
        template<typename T>
        class auto_ptr<std::vector<T> *>
        {
            public:
                auto_ptr<std::vector<T> *>();
        };

        template <typename T>
        inline auto_ptr<std::vector<T> * >::auto_ptr()
        {
            std::cout << "Vector specialization\n";
        }
    }
