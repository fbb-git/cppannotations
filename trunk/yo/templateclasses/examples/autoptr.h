    namespace FBB
    {
        template <typename Data>
        class auto_ptr
        {
            Data *d_data;

            public:
                auto_ptr();
                auto_ptr(auto_ptr<Data> &other);
                auto_ptr(Data *data);
                ~auto_ptr();
                auto_ptr<Data> &operator=(auto_ptr<Data> &rvalue);
                Data &operator[](size_t index);
                Data const &operator[](size_t index) const;
                Data *get();
                Data const *get() const;
                Data *release();
                void reset(Data *p = 0);
            private:
                void destroy();
                void copy(auto_ptr<Data> &other);
                Data &element(size_t idx) const;
        };

        template <typename Data>
        inline auto_ptr<Data>::auto_ptr()
        :
            d_data(0)
        {}

        template <typename Data>
        inline auto_ptr<Data>::auto_ptr(auto_ptr<Data> &other)
        {
            copy(other);
        }

        template <typename Data>
        inline auto_ptr<Data>::auto_ptr(Data *data)
        :
            d_data(data)
        {}

        template <typename Data>
        inline auto_ptr<Data>::~auto_ptr()
        {
            destroy();
        }

        template <typename Data>
        inline Data &auto_ptr<Data>::operator[](size_t index)
        {
            return d_data[index];
        }

        template <typename Data>
        inline Data const &auto_ptr<Data>::operator[](size_t index) const
        {
            return d_data[index];
        }

        template <typename Data>
        inline Data *auto_ptr<Data>::get()
        {
            return d_data;
        }

        template <typename Data>
        inline Data const *auto_ptr<Data>::get() const
        {
            return d_data;
        }

        template <typename Data>
        inline void auto_ptr<Data>::destroy()
        {
            delete[] d_data;
        }

        template <typename Data>
        inline void auto_ptr<Data>::copy(auto_ptr<Data> &other)
        {
            d_data = other.release();
        }

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

    } // FBB
