    #include <iostream>
    #include <complex>
    #include <stack>

    using namespace std;

    int main()
    {
        stack<complex<double> >
            cstack;

        cstack.push(complex<double>(3.14, 2.71));
        cstack.push(complex<double>(-3.14, -2.71));

        while (cstack.size())
        {
            cout << cstack.top().real() << ", " <<
                    cstack.top().imag() << "i" << endl;
            cstack.pop();
        }
    }
    /*
        Generated output:
    -3.14, -2.71i
    3.14, 2.71i
    */
