#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

using namespace std;

int &&rref();
int const &icref();

string const &text()
{
    static string txt = "text";
    return txt;
}

void fun(string const &text)
{
    auto s1{text};
    decltype(text) s2 = text;
}

struct Data
{
    vector<string> d_vs;
    string i_val;
    string *d_val = new string[10];

    Data()
    :
        d_vs(1)
    {}

    decltype(auto) vs() const
    {
        return d_vs[0];
    }

    decltype(auto) dt() const
    {
        return d_val[0];
    }

    auto au() const                 // returns: string
    {
        string &sr = d_val[0];
        return d_val[0];
    }

    auto vs2() const                 // returns: string
    {
        string const &sr = d_vs[0];
        return d_vs[0];
    }

};

int main()
{

//    int value = 12;
//    int *ip = &value;
//
//    int *const &ptr = ip;
//    auto ptr2 = ptr;        // int *
//
//    decltype(auto) ptr3 = ptr2;
//
//    cout << is_same< int *, decltype(ptr3) >::value << '\n';
//
//    decltype(auto) ptr4 = (ptr2);
//
//    cout << is_same< int * &, decltype(ptr4) >::value << '\n';
//
//    decltype(auto) ret = value + value;
//    cout << is_same< int, decltype(ret) >::value << '\n';
//
//    string lines[20];
//    decltype(auto) line = lines[0];
//    cout << is_same< string &, decltype(line) >::value << '\n';

//    decltype(auto) ref = string{};
//    cout << is_same< string, decltype(ref) >::value << '\n';

    Data data;
    cout << is_same< string const &, decltype(data.vs()) >::value << '\n';

//    cout << is_same< int *, decltype(ptr2) >::value << '\n';
//    cout << is_same< int * &, decltype((ptr2)) >::value << '\n';
//    cout << is_same< int, decltype((value + value)) >::value << '\n';
//
//    string &&strRref = string{};
//    decltype(strRref) lref = string{};
//
//    cout << is_same< string &&, decltype(lref) >::value << '\n';
//    cout << is_same< string &, decltype((lref)) >::value << '\n';
}
