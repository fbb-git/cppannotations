    #include <utility>
    #include <iostream>
    using namespace std;

    int main(int argc, char **argv)
    {
        bool more = argc > 5;
        
        cout << "more than 5: " << exchange(more, argc > 2) << 
                ", more than 2: " << more << '\n';
    }
    /*
        Using g++ at least version 7.0.0:
        With `a.out one two three' displays:

        more than 5: 0, more than 2: 1

    */
