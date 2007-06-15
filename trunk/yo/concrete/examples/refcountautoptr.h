#ifndef _INCLUDED_REFCOUNTAUTOPTR_H_
#define _INCLUDED_REFCOUNTAUTOPTR_H_

#include <cstddef>

    // Implementation of auto_ptr using reference counting.
    // This implementation was provided and offered for inclusion in the
    // C++ Annotations by Jesse van den Kieboom (jesse at icecrew.nl).

    template<typename Type>
    class auto_ptr
    {
        class auto_ptr_data
        {
            Type *d_ptr;
            size_t d_refcount;

            public:
                typedef Type element_type;

                auto_ptr_data(element_type *ptr = 0);
                ~auto_ptr_data();

                element_type *get() const;

                // Refcounting
                size_t refcount() const;
                auto_ptr_data *ref();
                bool unref();
                element_type *release();
            private:
                auto_ptr_data(auto_ptr_data const &other); // NI

                void destroy();
        };

        auto_ptr_data *d_data;

        public:
            /// The pointed-to type.
            typedef Type element_type;

            explicit auto_ptr(element_type *ptr = 0);
            auto_ptr(auto_ptr const &other);

            ~auto_ptr();

            // Assignment operator
            auto_ptr &operator=(auto_ptr &other);

            // Dereference operators
            element_type &operator*() const;
            element_type *operator->() const;

            // Get and release
            element_type *get() const;
            element_type *release();
            void reset(element_type *ptr = 0);
        private:
            void destroy();
    };

    /// auto_ptr_data
    template <typename Type>
    auto_ptr<Type>::auto_ptr_data::auto_ptr_data(element_type *ptr)
    :
        d_ptr(ptr),
        d_refcount(!ptr ? 0 : 1)
    {
    }

    template <typename Type>
    auto_ptr<Type>::auto_ptr_data::~auto_ptr_data()
    {
        // Destroy our pointer
        if (d_refcount)
            destroy();
    }

    template <typename Type>
    inline size_t auto_ptr<Type>::auto_ptr_data::refcount() const
    {
        return d_refcount;
    }

    template <typename Type>
    inline Type *auto_ptr<Type>::auto_ptr_data::get() const
    {
        return d_ptr;
    }

    template <typename Type>
    Type *auto_ptr<Type>::auto_ptr_data::release()
    {
        // This function releases the pointer so it's no longer
        // maintained by this object.

        if (!d_refcount)
            return 0;

        --d_refcount;

        Type *tmp = d_ptr;
        d_ptr = 0;

        return tmp;
    }

    // Refcounting
    template <typename Type>
    typename auto_ptr<Type>::auto_ptr_data
        *auto_ptr<Type>::auto_ptr_data::ref()
    {
        if (d_ptr)
            ++d_refcount;

        return this;
    }

    template <typename Type>
    bool auto_ptr<Type>::auto_ptr_data::unref()
    {
        if (!d_refcount)
            return false;

        --d_refcount;

        if (!d_refcount)
            destroy();

        return d_refcount != 0;
    }

    template <typename Type>
    void auto_ptr<Type>::auto_ptr_data::destroy()
    {
        delete d_ptr;
        d_ptr = 0;
    }


    /// auto_ptr
    template <typename Type>
    inline auto_ptr<Type>::auto_ptr(element_type *ptr)
    {
        d_data = new auto_ptr_data(ptr);
    }

    template <typename Type>
    inline auto_ptr<Type>::auto_ptr(auto_ptr const &other)
    :
        d_data(other.d_data->ref())
    {}

    template <typename Type>
    inline auto_ptr<Type>::~auto_ptr()
    {
        destroy();
    }

    template <typename Type>
    auto_ptr<Type> &auto_ptr<Type>::operator=(auto_ptr &other)
    {
        if (&other != this)
        {
            destroy();

            d_data = other.d_data->ref();
        }

        return *this;
    }

    template <typename Type>
    inline Type &auto_ptr<Type>::operator*() const
    {
        return *d_data->get();
    }

    template <typename Type>
    inline Type *auto_ptr<Type>::operator->() const
    {
        return d_data->get();
    }

    template <typename Type>
    inline Type *auto_ptr<Type>::get() const
    {
        return d_data->get();
    }

    // Warning: when releasing a refcounting auto pointer the data
    // itself is released and no longer maintained by any of the
    // auto pointers. All these auto pointers will now return 0.
    // It's your responsibility to handle this properly (and to
    // free the released pointer of course)
    template <typename Type>
    Type *auto_ptr<Type>::release()
    {
        Type *ptr = d_data->release();

        return ptr;
    }

    template <typename Type>
    void auto_ptr<Type>::reset(Type *ptr)
    {
        // Prevent creating a wild pointer by resetting
        if (ptr == d_data->get())
            return;

        // Unref current data
        destroy();

        // Set new data
        d_data = new auto_ptr_data(ptr);
    }

    template <typename Type>
    void auto_ptr<Type>::destroy()
    {
        if (!d_data->unref())
            delete d_data;
    }

#endif
