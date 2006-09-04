    #include <string>

    int main()
    {
        string
            stringOne("Hello World 12345678901234567890 "),
            stringTwo(5, 'a'),
            stringThree(stringOne.rbegin(), stringOne.rend());

        stringOne.resize(20, 'z');

        cout << "World at: " << stringOne.find("World") << endl;

        cout << stringOne << endl;

        stringTwo.append("hello world", 3, 5);

        stringTwo.insert(1, "...");

        cout << stringTwo << endl;
        cout << (stringOne.data() ? "not a 0 ptr." : "0 ptr.") << endl;
        cout << (stringTwo.data() ? "not a 0 ptr." : "0 ptr.") << endl;
        cout << stringOne.data() << endl << "'" << stringTwo.data() << "'"
                << endl;

        cout << stringOne.max_size() << ", " << stringOne.capacity() << endl;
        cout << stringTwo.max_size() << ", " << stringTwo.capacity() << endl;
        return (0);
    }
