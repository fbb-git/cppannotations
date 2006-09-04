    namespace FBB
    {
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


