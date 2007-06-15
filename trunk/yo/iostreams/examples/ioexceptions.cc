    #include <iostream>

    using namespace std;

    int main()
    {
        cout << "Enter a word, not a number: ";
        cin.exceptions(ios::failbit);
        int
            x;
        try
        {
            cin >> x;
        }
        catch(ios::failure failure)
        {
            cout << "Here's what: " << failure.what() << endl;
        }
    }
    /*
        Generated output:
    Enter a word, not a number: grandpa
    Here's what: basic_ios::clear(iostate) caused exception
    */
