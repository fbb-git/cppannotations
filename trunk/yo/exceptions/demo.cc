    #include <iostream.h>

    void intThrower() throw(int);
    void charP_IntThrower() throw (char *, int);

    void intThrower(int x) throw (int)
    {
        if (x)
            throw x;
    }

    void charP_IntThrower() throw (char *, int)
    {
        int
            x;
        cout << "Enter an int: ";
        cout.flush();
        cin >> x;

        intThrower(x);
        throw "from charP_IntThrower() with love";

    }

    int main()
    {
        try
        {
             charP_IntThrower();
        }
        catch (char *message)
        {
            cout << "Text exception: " << message << '\n';
        }
        catch (int value)
        {
            cout << "Int exception: " << value << '\n';
        }
        return (0);
    }
