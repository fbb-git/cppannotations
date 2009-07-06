#include <iostream>
#include <tuple>

#include <string>


using namespace std;

int main()
{
    typedef std::tuple<int, double &, std::string, char const *> tuple_idsc;
    
    double pi = 3.14;
    tuple_idsc idsc(59, pi, "hello", "fixed");
    tuple_idsc empty;

    cout << tuple_size<tuple_idsc>::value << endl;
    tuple_element<2, tuple_idsc>::type text("hi");

    // access a field:
    get<2>(idsc) = "hello world";
}
