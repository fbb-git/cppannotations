    #include <iostream>
    #include <algorithm>

    namespace FBB
    {
        template <typename Data, size_t Size>
        class auto_ptr
        {
            Data *d_data;
            size_t d_n;

            public:
                auto_ptr()
                :
                    d_data(0),
                    d_n(0)
                {}
                auto_ptr(auto_ptr<Data, Size> &other)
                {
                    copy(other);
                }

                auto_ptr(Data *data)
                :
                    d_data(data),
                    d_n(0)
                {
                    std::cout << "pointer\n";
                }

                auto_ptr(Data const (&arr)[Size])
                :
                    d_data(new Data[Size]),
                    d_n(Size)
                {
                    std::cout << "fixed array\n";
                    std::copy(arr, arr + Size, d_data);
                }
                ~auto_ptr()
                {
//                    destroy();
                }
                auto_ptr<Data, Size> &operator=(auto_ptr<Data, Size> &rvalue);
                Data &operator[](size_t index)
                {
                    return d_data[index];
                }
                Data const &operator[](size_t index) const
                {
                    return d_data[index];
                }
                Data *get()
                {
                    return d_data;
                }
                Data const *get() const
                {
                    return d_data;
                }
                Data *release();
                void reset(Data *);
            private:
                void destroy()
                {
                    delete[] d_data;
                }
                void copy(auto_ptr<Data, Size> &other)
                {
                    d_data = other.release();
                }
                Data &element(size_t idx) const;
        };
    }
