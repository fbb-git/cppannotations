/*
    Cloneable template class protects a derived object from slicing when
    used with stl containers

    Author: Jesse van den Kieboom

    Jesse provides the following example based on his class template Cloneable:

        vector<Cloneable<A> > vec;

        vec.push_back(B());
        vec.push_back(B());

        Cloneable<A> a = B();
        a->(functie op A/B)

        Cloneable<B> b = B();
        a = b;

*/
#ifndef __CLONEABLE_H__
#define __CLONEABLE_H__

namespace jessevdk
{
    template <typename Base>
    class Cloneable
    {
        Base *d_base;

        public:
            /* Default constructor */
            Cloneable();

            template <typename Other>
            Cloneable(Cloneable<Other> const &other);

            /* Specialisation needed to override default copy constructor */
            Cloneable(Cloneable<Base> const &other);

            template <typename Other>
            Cloneable(Other const &other);

            /* Deconstructor */
            virtual ~Cloneable();

            /* Public functions */
            template <typename Other>
            Cloneable<Base> &operator=(Cloneable<Other> const &other);

            /* Specialisation needed to override default assignment operator */
            Cloneable<Base> &operator=(Cloneable<Base> const &other);

            template <typename Other>
            Cloneable<Base> &operator=(Other const &other);

            /* Operators */
            Base &operator*();
            Base const &operator*() const;

            Base *operator->();
            Base const *operator->() const;
            operator Base&();
        private:
            /* Private functions */
            void destroy();

            template <typename Other>
            Cloneable<Base> &assign(Other const &other);
    };

    /* Constructors */
    template <typename Base>
    inline Cloneable<Base>::Cloneable()
    {
        d_base = new Base();
    }

    template <typename Base>
    template <typename Other>
    inline Cloneable<Base>::Cloneable(Other const &other)
    {
        /* Clone other */
        d_base = other.clone();
    }

    template <typename Base>
    inline Cloneable<Base>::Cloneable(Cloneable<Base> const &other)
    {
        /* Clone other from cloneable */
        d_base = other->clone();
    }

    template <typename Base>
    template <typename Other>
    inline Cloneable<Base>::Cloneable(Cloneable<Other> const &other)
    {
        /* Clone other from cloneable */
        d_base = other->clone();
    }

    /* Destructor */
    template <typename Base>
    inline Cloneable<Base>::~Cloneable()
    {
        destroy();
    }

    template <typename Base>
    template <typename Other>
    Cloneable<Base>& Cloneable<Base>::assign(Other const &other)
    {
        /* Assign other to this cloneable with self-destroy check */
        if (d_base != &other)
        {
            destroy();
            d_base = other.clone();
        }

        return *this;
    }

    template <typename Base>
    Cloneable<Base>& Cloneable<Base>::operator=(Cloneable<Base> const &other)
    {
        return assign(*other);
    }

    template <typename Base>
    template <typename Other>
    Cloneable<Base>& Cloneable<Base>::operator=(Cloneable<Other> const &other)
    {
        return assign(*other);
    }

    template <typename Base>
    template <typename Other>
    Cloneable<Base>& Cloneable<Base>::operator=(Other const &other)
    {
        return assign(other);
    }

    template <typename Base>
    inline void Cloneable<Base>::destroy()
    {
        delete d_base;
    }

    /* Operators */
    template <typename Base>
    inline Base &Cloneable<Base>::operator*()
    {
        return *d_base;
    }

    template <typename Base>
    inline Base *Cloneable<Base>::operator->()
    {
        return d_base;
    }

    template <typename Base>
    inline Base const &Cloneable<Base>::operator*() const
    {
        return *d_base;
    }

    template <typename Base>
    inline Base const *Cloneable<Base>::operator->() const
    {
        return d_base;
    }

    template <typename Base>
    inline Cloneable<Base>::operator Base&()
    {
        return *d_base;
    }
}

#endif /* __CLONEABLE_H__ */
