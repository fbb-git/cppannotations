    class Vector
    {
        public:
            Vector(int *vector, unsigned size)
            :
                vector(vector),
                current(vector),
                finish(vector + size)
            {}
            int *begin()
            {
                return(current = vector);
            }
            operator int *() const
            {
                return (current);
            }
            // increment and decrement operators: see the text
        private:
            int
                *vector,
                *current,
                *finish;
    };
