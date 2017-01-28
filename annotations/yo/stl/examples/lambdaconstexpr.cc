constexpr int add(int n)
{
//    return [n] () constexpr { return n > 10 ? n - 10 : n + 10; }();
    return [n]  { return n > 10 ? n - 10 : n + 10; }();
}

auto id = [] (int n ) constexpr { return n; };
constexpr int x = id(4);

auto id2 = [] (int n ) { return n; };
constexpr int x2 = id2(4);

auto add2 = [] (int n) { return n + 10 ; };

int constexpr (*fp)(int) = add2;

static_assert(fp(3) == add2(3), "");

auto monoid = [](auto v)
                {
                    return [=]
                            { return v;
                            };
                };

auto add3 = [](auto m1) constexpr
{
    auto ret = m1();
    return [=] (auto m2) mutable
    {
        auto m1val = m1();
        auto plus = [=] (auto m2val) mutable constexpr
                    {
                        return m1val += m2val;
                    };
        ret = plus(m2());
        return monoid(ret);
    };
};

//ifconst
void positive();
void negative();

template <int value>
void fun()
{
    if constexpr (value > 0)
        positive();
    else if constexpr (value < 0)
        negative();
}

int main()
{
    fun<4>();
}
//=
