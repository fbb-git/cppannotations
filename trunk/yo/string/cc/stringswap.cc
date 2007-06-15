    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string stringOne("Hello");
        string stringTwo("World");

        cout << "Before: stringOne: " << stringOne << ", stringTwo: "
            << stringTwo << endl;

        stringOne.swap(stringTwo);

        cout << "After: stringOne: " << stringOne << ", stringTwo: "
            << stringTwo << endl;
    }
