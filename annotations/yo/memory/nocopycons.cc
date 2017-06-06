class Class
{
    public:
        Class() = default;
        Class(Class &&tmp)
        {}
};

int main()
{
    Class one;
    Class two{ one };
}
