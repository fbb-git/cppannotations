    #include <iostream>
    using namespace::std;

    int main()
    {
        cin.exceptions(ios::failbit);

        while (true)
        {
            try
            {
                cout << "enter a number: ";

                int value;

                cin >> value;
                cout << "you entered " << value << endl;
            }
            catch (ios::failure const &problem)
            {
                cout << problem.what() << endl;
                cin.clear();
                string s;
                getline(cin, s);
            }
        }
    }
