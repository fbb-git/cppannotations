    #include <stdio.h>

    void show(int val)
    {
        printf("Integer: %d\n", val);
    }

    void show(double val)
    {
        printf("Double: %lf\n", val);
    }

    void show(char const *val)
    {
        printf("String: %s\n", val);
    }

    int main()
    {
        show(12);
        show(3.1415);
        show("Hello World\n!");
    }
