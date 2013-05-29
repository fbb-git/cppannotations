    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string stringOne("Hello");
        string stringTwo("World");

        stringOne += " " + stringTwo;

        stringOne = "hello";
        stringOne.append(" world");
                                        // append 5 characters:
        stringOne.append(" ok. >This is not used<", 5);

        cout << stringOne << '\n';

        string stringThree("Hello");
                                        // append " world":
        stringThree.append(stringOne, 5, 6);

        cout << stringThree << '\n';
    }
