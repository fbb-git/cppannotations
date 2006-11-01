    #include <iostream>
    #include <algorithm>
    #include "autoptr1.h"

    namespace FBB
    {
        template<>
        class auto_ptr<char *>
        {
            char **d_data;
            size_t d_n;

            public:
                auto_ptr<char *>()
                :
                    d_data(0),
                    d_n(0)
                {}
                auto_ptr<char *>(auto_ptr<char *> &other)
                {
                    copy(other);
                }
                auto_ptr<char *>(char **argv)
                {
                    full_copy(argv);
                }
                // template <size_t Size>             NI
                // auto_ptr(char *const (&arr)[Size])
                ~auto_ptr()
                {
                    destroy();
                }
                auto_ptr<char *> &operator=(auto_ptr<char *> &rvalue);
                char *&operator[](size_t index);
                char *const &operator[](size_t index) const;
                char **get();
                char *const *get() const;
                char **release();
                void reset(char **argv)
                {
                    destroy();
                    full_copy(argv);
                }
                void additional() const     // just an additional public
                {}                          // member

            private:
                void full_copy(char **argv)
                {
                    d_n = 0;
                    char **tmp = argv;
                    while (*tmp++)
                        d_n++;
                    d_data = new char *[d_n];

                    for (size_t idx = 0; idx < d_n; idx++)
                    {
                        std::string str(argv[idx]);
                        d_data[idx] =
                            strcpy(new char[str.length() + 1], str.c_str());
                    }
                }
                void copy(auto_ptr<char *> &other);
                void destroy();             // implemented below
        };

        void auto_ptr<char *>::destroy()
        {
            while (d_n--)
                delete d_data[d_n];
            delete[] d_data;
        }
    }
