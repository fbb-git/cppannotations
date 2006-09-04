    namespace FBB
    {
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
    }


