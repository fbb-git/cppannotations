template <typename T>
concept bool C = true;

auto gl = [](C &lhs, C const *rhs)
            {
                lhs = *rhs;
            };

int main()
{
    int x;

    gl(x, &x);
}


