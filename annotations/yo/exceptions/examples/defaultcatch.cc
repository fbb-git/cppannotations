    #include <iostream>
    using namespace std;

    int main()
    {
        try
        {
            try
            {
                throw 12.25;    // no specific handler for doubles
            }
            catch (int value)
            {
                cout << "Inner level: caught int\n";
            }
            catch (...)
            {
                cout << "Inner level: generic handling of exceptions\n";
                throw;
            }
        }
        catch(double d)
        {
            cout << "Outer level may use the thrown double: " << d << '\n';
        }
    }
    /*
        Generated output:
    Inner level: generic handling of exceptions
    Outer level may use the thrown double: 12.25
    */
