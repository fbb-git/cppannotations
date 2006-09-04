    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <iterator>

//SORTWITH
    template <typename Type>
    class SortWith
    {
       bool (Type::*d_ptr)(Type const &rhv) const;
//=
        public:
//SORTCONS
            SortWith(bool (Type::*ptr)(Type const &rhv) const)
            :
                d_ptr(ptr)
            {}
//=
//OPERATOR
            bool operator()(Type const &lhv, Type const &rhv) const
            {
                return (lhv.*d_ptr)(rhv);
            }
//=
    };
//HEAD
    template <typename Type>
    class SortVector: public std::vector<Type>
    {
        public:
            SortVector()
            {}
            SortVector(Type const *begin, Type const *end)
            :
                std::vector<Type>(begin, end)
            {}
//=
            void hierarchicalSort
            (
                bool (Type::**arr)(Type const &rhv) const,
                unsigned n
            );
    };

//SORT
    template <typename Type>
    void SortVector<Type>::hierarchicalSort(
                bool (Type::**arr)(Type const &rhv) const,
                unsigned n)
    {
        while (n--)
            stable_sort(begin(), end(), SortWith<Type>(arr[n]));
    }
//=
    class MultiData;
    namespace std
    {
        ostream &operator<<(ostream &str, MultiData const &obj);
        istream &operator>>(istream &str, MultiData &obj);
    }

    class MultiData
    {
        friend std::ostream
                &std::operator<<(std::ostream &str, MultiData const &obj);
        friend std::istream
                &std::operator>>(std::istream &str, MultiData &obj);

        std::string d_text;
        int         d_value;

        public:
            bool textCmp(MultiData const &rhv) const
            {
                return d_text < rhv.d_text;
            }
            bool intCmp(MultiData const &rhv) const
            {
                return d_value < rhv.d_value;
            }
    };

    namespace std
    {
        ostream &operator<<(ostream &output, MultiData const &obj)
        {
            return output << obj.d_text << " " << obj.d_value;
        }
        istream &operator>>(istream &input, MultiData &obj)
        {
            return input >> obj.d_text >> obj.d_value;
        }
    }

    using namespace std;

    int main()
    {
//MAIN1
        SortVector<MultiData> sv;

        copy(istream_iterator<MultiData>(cin),
                istream_iterator<MultiData>(),
                back_inserter(sv));
//=
        copy(sv.begin(), sv.end(),
            ostream_iterator<MultiData>(cout, " "));

        cout << "\n====\n";
//ARRAY
        bool (MultiData::*arr[])(MultiData const &rhv) const =
        {
            &MultiData::textCmp,
            &MultiData::intCmp,
        };
//=
//SORT1
        sv.hierarchicalSort(arr, 2);
//=
        copy(sv.begin(), sv.end(),
            ostream_iterator<MultiData>(cout, " "));

        cout << "\n====\n";
//SORT2
        swap(arr[0], arr[1]);
        sv.hierarchicalSort(arr, 2);
//=
        copy(sv.begin(), sv.end(),
            ostream_iterator<MultiData>(cout, " "));

        cout << "\n====\n";
    }
