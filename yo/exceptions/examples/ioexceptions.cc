    #include <iostream>
    #include <climits>
    using namespace::std;

    int main()
    {
        cin.exceptions(ios::failbit);   // throw exception on fail
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
                cin.ignore(INT_MAX, '\n');  // ignore the faulty line
            }
        }
    }
