With function templates the combination of the types of template arguments and
template parameters shows some interesting contractions. What happens, for
example if a template type parameter is specified as an rvalue reference but
an lvalue reference argument type is provided?

In such cases the compiler performs type contractions. Doubling identical
reference types results in a simple contraction: the type is deduced to be a
single reference type. Example: if the template parameter type is specified as
a tt(Type &&) and the actual parameter is an tt(int &&) then tt(Type) is
deduced to be an tt(int), rather than an tt(int &&).

This is fairly intuitive. But what happens if the actual type is tt(int &)?
There is no such thing as an tt(int & &&param) and so the compiler contracts
the double reference by removing the rvalue reference, keeping the lvalue
reference. Here a simple rule is followed: Any reference to an lvalue
reference results in an lvalue reference and emi(vice versa): an lvalue to any
reference also results in an lvalue:
    itemization(
    it() if tt(Type) is tt(Actual &) then tt(Type &) is tt(Actual &) and
tt(Type == Actual);
    it() if tt(Type) is tt(Actual &) then tt(Type &&) still is tt(Actual &)
and tt(Type == Actual);
    it() if tt(Type) is tt(Actual &&) then tt(Type &) again is tt(Actual &)
and tt(Type == Actual);
    it() if tt(Type) is tt(Actual &&) then tt(Type &&)  is tt(Actual &&)
and tt(Type == Actual);
    )

