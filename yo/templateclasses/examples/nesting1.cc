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

                iterator(PtrVector<Type> &vector)
                :
                    d_begin(vector.std::vector<Type *>::begin())
                {}
                public:
                    Type &operator*()
                    {
                        return **d_begin;
                    }
            };
//=
//BEGIN
            iterator begin()
            {
                return iterator(*this);
            }
//=
    };

    using namespace std;
//MAIN
    int main()
    {
        PtrVector<int> vi;

        vi.push_back(new int(1234));

        PtrVector<int>::iterator begin = vi.begin();

        std::cout << *begin << endl;
    }
//=
