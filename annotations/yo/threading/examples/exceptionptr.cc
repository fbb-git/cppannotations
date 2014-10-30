#include <future>
#include <iostream>
#include <string>
using namespace std;

int main()
try
{
    exception_ptr ep;

    if (ep == 0)
        cerr << "null ptr\n";

//    promise<int> p;

    try
    {
        try
        {
            throw 1;
        }
        catch (...)
        {
            auto ep = current_exception();
            if (ep == 0)
                cerr << "current_exc. equals null if an int is thrown\n";
            rethrow_exception(ep);
        }
    }
    catch (int x)
    {
        cerr << "CAUGHT " << x << '\n';
    }
    catch (...)
    {
        cerr << "catch all\n";
    }

    ep = make_exception_ptr(exception());
    exception_ptr e2(ep);

    e2 = ep;

    if (ep == e2)
        cerr << "equal exc. ptrs\n";

    e2 = move(ep);

    if (ep != e2)
        cerr << "after move: unequal exc. ptrs\n";

    if (ep == 0)
        cerr << "after move: the rhs is 0\n";

//    p.set_exception(make_exception_ptr(exception()));
//    p.set_exception(make_exception_ptr(12));
//    p.set_exception(make_exception_ptr(string("hello")));

    rethrow_exception(make_exception_ptr(12));

}
catch (int x)
{
    cerr << "caught " << x << '\n';
}
catch (exception const &e)
{
    cerr << "caught exception object: " << e.what() << "\n";
}
catch (string const  &s)
{
    cerr << "caught string object\n";
}
catch (...)
{
    cerr << "caught unspecified exception\n";
}
