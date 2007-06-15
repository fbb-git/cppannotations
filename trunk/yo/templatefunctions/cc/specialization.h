    #include "sumvector.h"
    #include <string>

    template <> char *sumVector<char *>(char **argv, size_t argc)
    {
        std::string s = std::accumulate(argv, argv + argc, std::string());

        return strcpy(new char[s.size() + 1], s.c_str());
    }
