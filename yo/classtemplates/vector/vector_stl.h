    #include <algorithm>
/*
    template <typename Iterator>
    struct iterator_types
    {
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
    };
*/
    template <typename T>
    struct iterator_types //<T*>
    {
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template <typename Iterator>
    class reverse_iter
    {
        public:
            typedef typename iterator_types<Iterator>::pointer     pointer;
            typedef typename iterator_types<Iterator>::reference   reference;

            explicit reverse_iter(Iterator x)
            :
                current(x)
            {}
            reference operator*() const
            {
                Iterator
                    tmp = current;
                return (*--tmp);
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            reverse_iter<Iterator>& operator++()
            {
                --current;
                return (*this);
            }
            reverse_iter<Iterator> operator++(int)
            {
                reverse_iter<Iterator>
                    tmp(current--);
                return (tmp);
            }
            bool operator!=(reverse_iter<Iterator> const &other)
            {
                return (current != other.current);
            }
        private:
            Iterator current;
    };

    template <typename Type>
    class Vector
    {
        typedef Type *iterator;
        typedef reverse_iter<iterator> reverse_iterator;

        public:
            Vector()
            {
                init(0);
            };
            Vector(size_t n)
            {
                init(n);
            }
            Vector(Vector<Type> const &other)
            {
                construct(other);
            }
            ~Vector()
            {
                delete[] start;
            }
            Vector<Type> const &operator=(Vector<Type> const &other)
            {
                if (this != &other)
                {
                    delete[] start;
                    construct(other);
                }
                return (*this);
            }
            Type &operator[](size_t index) throw(char const *)
            {
                if (index > (finish - start))
                    throw "Vector array index out of bounds";
                return (start[index]);
            }
            Vector<Type> &sort()
            {
                ::sort(start, finish);
                return (*this);
            }
            void push_back(Type const &value)
            {
                if (!finish)
                    init(1);
                else if (finish == end_of_storage)
                {
                    Vector<Type>
                        enlarged((end_of_storage - start) << 1);
                    copy(start, finish, enlarged.start);
                    delete[] start;
                    finish = enlarged.start + (finish - start);
                    start = enlarged.start;
                    end_of_storage = enlarged.end_of_storage;
                    enlarged.start = 0;
                }
                *finish++ = value;
            }
            iterator begin()
            {
                return (start);
            }
            iterator end()
            {
                return (finish);
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(finish));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(start));
            }
            size_t size()
            {
                return (finish - start);
            }
        private:
            void init(size_t n)
            {
                if (n)
                {
                    start = new Type[n];
                    finish = start + n;
                    end_of_storage = start + n;
                }
                else
                {
                    start = 0;
                    finish = 0;
                    end_of_storage = 0;
                }
            }
            void construct(Vector<Type> const &other)
            {
                init(other.finish - other.start);
                copy(other.start, other.finish, start);
            }

            iterator
                start,
                finish,
                end_of_storage;
    };
