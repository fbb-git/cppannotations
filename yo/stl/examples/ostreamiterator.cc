    #include <iostream>
    #include <algorithm>
    #include <iterator>
    using namespace std;

    int main()
    {
        cin.unsetf(ios::skipws);
        copy(istream_iterator<char>(cin), istream_iterator<char>(),
             ostream_iterator<char>(cout));
    }
