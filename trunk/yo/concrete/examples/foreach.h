
//FOREACH1
    template <typename Iterator, typename Class, typename Data>
    Class &ForEach(Iterator begin, Iterator end, Class &object,
                        void (Class::*member)(Data &))
    {
        while (begin != end)
            (object.*member)(*begin++);

        return object;
    }
//=

//FOREACH2
    template <typename Iterator, typename Class, typename Data>
    Class &ForEach(Iterator begin, Iterator end, Class &object,
                    void (Class::*member)(Data &) const)
    {
        while (begin != end)
            (object.*member)(*begin++);

        return object;
    }
//=

//FOREACH3
    template <typename Iterator, typename Class>
    Class &ForEach(Iterator begin, Iterator end, Class &object)
    {
        while (begin != end)
            object(*begin++);

        return object;
    }
//=

//FOREACH4
    template <typename Iterator, typename Data>
    void ForEach(Iterator begin, Iterator end,
            Data(*function)(Data))
    {
        for (; begin != end; ++begin)
            *begin = function(*begin);
    }
//=
