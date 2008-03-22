#include <iostream>
#include <vector>

template <typename Data>
struct Plain: public std::pair<Data *, Data *>
{};

template <typename Data, template <typename> class Container>
struct Size: public Container<Data>
{
    size_t size()
    {
        // for illustrative purposes:
        this->push_back(Data());

        return Container<Data>::size();
    }
};

template <typename Data>
struct Size<Data, Plain>: public Plain<Data>
{
    size_t size()
    {
          return this->second - this->first;
    }
};

template <typename Data, template <typename> class Store>
class Wrapper: public Size<Data, Store>
{};

using namespace std;

int main()
{
    Wrapper<int, vector> wiv;
    cout << wiv.size() << endl;

    Wrapper<int, Plain> wis;
    cout << wis.size() << endl;

}
