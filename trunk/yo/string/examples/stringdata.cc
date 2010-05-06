    #include <string>

    int main()
    {
        string
            stringOne("Hello World 12345678901234567890 "),
            stringTwo(5, 'a'),
            stringThree(stringOne.rbegin(), stringOne.rend());

        stringOne.resize(20, 'z');

        cout << "World at: " << stringOne.find("World") << '\n';

        cout << stringOne << '\n';

        stringTwo.append("hello world", 3, 5);

        stringTwo.insert(1, "...");

        cout << stringTwo << '\n';
        cout << (stringOne.data() ? "not a 0 ptr." : "0 ptr.") << '\n';
        cout << (stringTwo.data() ? "not a 0 ptr." : "0 ptr.") << '\n';
        cout << stringOne.data() << '\n' << "'" << stringTwo.data() << "'"
                << '\n';

        cout << stringOne.max_size() << ", " << stringOne.capacity() << '\n';
        cout << stringTwo.max_size() << ", " << stringTwo.capacity() << '\n';
        return (0);
    }
