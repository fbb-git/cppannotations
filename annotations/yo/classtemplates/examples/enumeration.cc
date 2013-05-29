/*
    #include <vector>

    template<typename Type>
    class TheVector
    {
        public:
            class Enumeration
            {
                public:
                    Enumeration(vector<Type> const &vector)
                    :
                        vp(&vector),
                        idx(0)
                    {
                    }
                    Type const &nextElement()   // uses 'Type'
                    {
                        if (idx == vp->size())
                            throw NoSuchElementException(index);
                        return ((*vp)[idx++]);
                    }
                    bool hasMoreElements()
                    {
                        return (idx < vp->size());
                    }
                private:
                    vector<Type>
                        const *vp;
                    size_t
                        idx;
            };

            TheVector<Type>::Enumeration enumeration()
            {
                return (Enumeration(vector));
            }
        private:
            vector<Type>
                vector;
    };

    int main()
    {
        TheVector<int>
            theVector;

        TheVector<int>::Enumeration
            en = theVector.enumeration();

        cout << (en.hasMoreElements() ? "has more elements" :
                                        "no more elements") << '\n';

        return (0);
    }
*/
