    template <typename Type>
    class Vector
    {
        void construct(Vector<Type> const &other);
        Type
            *d_start,
            *d_finish,
            *d_end_of_storage;
        public:
            typedef reverse_iter<Type> reverse_iterator;

            Vector();
            Vector(size_t n);
            Vector(Vector<Type> const &other);
            ~Vector();
            Vector<Type> const &operator=(Vector<Type> const &other);
            Type &operator[](int index);
            Vector<Type> &sort();
            void push_back(Type const &value);
            Type *begin();
            Type *end();
            reverse_iterator rbegin();
            reverse_iterator rend();
            size_t size();
    };
