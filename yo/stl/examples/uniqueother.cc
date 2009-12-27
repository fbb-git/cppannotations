    #include <iostream>
    #include <memory>
    #include <string>

    using namespace std;

    int main()
    {
        unique_ptr<string> hello1(new string("Hello world"));
        unique_ptr<string> hello2(move(hello1));
        unique_ptr<string> hello3;

        hello3 = move(hello2);
        cout << // *hello1 << /\n' <<   // would have segfaulted
                // *hello2 << '\n' <<   // same
                *hello3 << '\n';
    }
    // Displays:    Hello world
