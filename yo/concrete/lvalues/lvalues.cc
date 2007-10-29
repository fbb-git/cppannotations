#include <iostream>
#include <vector>

using namespace std;

class Data 
{
    friend class Wrapper;   // Our Wrapper class is allowed to access our data
                            // too.

    vector<int> d_v;        // here are Data's data

    public:
        class Wrapper 
        {
            Data & d_data;
            size_t d_index;

            public:
                // For all situations in which data[x] is used as lvalue,
                // an operator must be defined accepting data[x] as lvalue and
                // all acceptable types as rvalue. Here I've defined two, but
                // generalizations are straightforward:


                Wrapper &operator=(Wrapper const &other);
                    // Use our (*this) data as lvalue, the other's data as
                    // rvalue. This is just one situation where our data are
                    // used as lvalue. If data[x] += data[y] is needed too,
                    // then that operator must be defined as well.

                Wrapper &operator=(int value);
                    // Our data as lvalue. This again is but one example. To
                    // implement data[x] += y etc, those operators must be 
                    // overloaded too.


                // There's only one situation where data[x] is used as rvalue:
                // when it's returning its data[x] element. This is
                // accomplished by defining the appropriate conversion
                // operator: 

                operator int() const;
                    // Our data as rvalue. Can't use things like int &n =
                    // data[3] or int *p = &data[3] here, because the data[3]
                    // expression is parsed as an rvalue, returning an int (in
                    // this case).  so if you want to use that, define an
                    // explicit reference and/or pointer returning member,
                    // like int &n = data.ref(3).

            private:
                // nobody but Data has anything to do with Wrapper's 
                // constructor so it's made private, declaring Data as its 
                // friend.

                friend class Data;

                Wrapper(Data &data, size_t index);
        };

        Data();
            
        int operator[](size_t index) const;
            // Always rvalue: operator[] of const objects
  
        Wrapper operator[](size_t index);
            // With non-const objects: the Wrapper is returned, to which
            // a value can be assigned, in which case it's is an lvalue, or
            // whose value can be requested, in which case the int-conversion
            // operator is called.
};


// I've defined all members inline, although you shouldn't do so in real life.


inline Data::Wrapper &Data::Wrapper::operator=(Wrapper const &other) 
{ 
    cout << "data[x] = data[y], lvalue = rvalue\n";

    d_data.d_v[d_index] = other.d_data.d_v[other.d_index];
    cout << "assignment performed\n";

    return *this;
}

inline Data::Wrapper &Data::Wrapper::operator=(int value)
{
    cout << "data[x] = y, lvalue = expression\n";

    d_data.d_v[d_index] = value;

    return *this;
}

inline Data::Wrapper::operator int() const
{
    cout << "using the conversion operator, "
            "returning an rvalue\n";

    return d_data.d_v[d_index];
}

inline Data::Wrapper::Wrapper(Data &data, size_t index)
: 
    d_data(data), 
    d_index(index) 
{}

inline Data::Data()
:   
    d_v(5)
{
    for (size_t idx = 0; idx < 5; ++idx)    // assign some values
        d_v[idx] = 2 * idx;
}
    
inline int Data::operator[](size_t index) const 
{
    cout << "rvalue-only from const object\n";
    return d_v[index];
}

inline Data::Wrapper Data::operator[](size_t index) 
{
    return Wrapper(*this, index);
}




int main() 
{
    Data test;              // a non-const object

    Data const testConst;   // a const object (normally via, e.g., a
                            // 'Data const &' parameter

                            // insert some (r)values:
    cout << "Inserting rvalues:\n" <<
            test[1] << " " << test[2] << "\n\n";

    cout << "data[x] to data[y] assignment:\n";
    test[1] = test[2];
    cout << "Resulting in: " << test[1] << " " << test[2] << "\n\n";

    cout << "Assignment from testConst:\n";
    test[1] = testConst[4];
    cout << "Resulting in: " << test[1] << "\n\n";

    cout << "Direct assignment to test[0] (now " << test[0] << 
                                                        ") as an lvalue:\n";
    test[0] = 11;
    cout << "Resulting in: " << test[0] << "\n\n";

    cout << "Using test[1] (= " << test[1] << 
                                        " + 2) in an expression as rvalue\n";
    int n = test[1] + 2;

    return 0;
}
