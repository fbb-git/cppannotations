    #include <string>

    int main()
    {
        string
            stringOne("Hell ok.");
                            // Insert "o " at position 4
        stringOne.insert(4, "o ");

        string
            world("The World of C++");

                            // insert "World" into stringOne
        stringOne.insert(6, world, 4, 5);

        cout << "Guess what ? It is: " << stringOne << endl;
    }
