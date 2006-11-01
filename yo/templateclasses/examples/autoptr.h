    namespace FBB
    {
        template <typename Data>
        class auto_ptr
        {
            Data *d_data;

            public:
                auto_ptr()
                :
                    d_data(0)
                {}
                auto_ptr(auto_ptr<Data> &other)
                {
                    copy(other);
                }
                auto_ptr(Data *data)
                :
                    d_data(data)
                {}
                ~auto_ptr()
                {
                    destroy();
                }
                auto_ptr<Data> &operator=(auto_ptr<Data> &rvalue);
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
                void copy(auto_ptr<Data> &other)
                {
                    d_data = other.release();
                }
                Data &element(size_t idx) const;
        };

        template <typename Data>
        auto_ptr<Data> &auto_ptr<Data>::operator=(auto_ptr<Data> &rvalue)
        {
            if (this != &rvalue)
            {
                destroy();
                copy(rvalue);
            }
            return *this;
        }

        template <typename Data>
        Data *auto_ptr<Data>::release()
        {
            Data *ret = d_data;
            d_data = 0;
            return ret;
        }

        template <typename Data>
        void auto_ptr<Data>::reset(Data *ptr)
        {
            destroy();
            d_data = ptr;
        }
    }
