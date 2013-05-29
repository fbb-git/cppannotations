    #include <memory>
    #include <string>

    int main()
    {
        auto_ptr<string>
            first;

        {
            auto_ptr<string>
                second(new string("Hello world"));

            first.reset(second.release());

            cout << "Second auto_ptr still points at: " << *second << '\n'
                << "First auto_ptr also points to: " << *first << '\n';
        }
        cout << "Second object now out of scope. First auto_ptr\n"
            "still points at: " << *first << '\n';
    }
