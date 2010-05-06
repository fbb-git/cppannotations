    #include <iostream>
    #include <vector>

//HEAD
    template <typename Type>
    class PtrVector: public std::vector<Type *>
//=
    {
        public:
//ITER
            class iterator
            {
                friend class PtrVector<Type>;
                typename std::vector<Type *>::iterator d_begin;

                iterator(PtrVector<Type> &vector);

                public:
                    Type &operator*();
            };
//=
            iterator begin();
    };

//ITERIMP
    template <typename Type>
    PtrVector<Type>::iterator::iterator(PtrVector<Type> &vector)
    :
        d_begin(vector.std::vector<Type *>::begin())
    {}

    template <typename Type>
    Type &PtrVector<Type>::iterator::operator*()
    {
        return **d_begin;
    }
//=
//BEGIN
    template <typename Type>
    typename PtrVector<Type>::iterator PtrVector<Type>::begin()
    {
        return iterator(*this);
    }
//=

    using namespace std;
//MAIN
    int main()
    {
        PtrVector<int> vi;

        vi.push_back(new int(1234));

        PtrVector<int>::iterator begin = vi.begin();

        std::cout << *begin << '\n';
    }
//=
