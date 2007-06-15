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
            catch (char const *message)
            {
                cout << "Inner level: caught char const *\n";
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
            cout << "Outer level still knows the double: " << d << endl;
        }
    }
    /*
        Generated output:
    Inner level: generic handling of exceptions
    Outer level still knows the double: 12.25
    */
