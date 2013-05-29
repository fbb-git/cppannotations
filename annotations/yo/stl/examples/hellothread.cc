    #include <thread>
    #include <iostream>
    #include <unistd.h>
    
    using namespace std;
    
    // do not forget to use -pthread with g++
    
    void fun(size_t count, char const *txt)
    {
    
        for (; count--; )
            cout << txt << endl;
    }
    int main()
    {                   // runs the thread following
                        // the object construction
        thread display(fun, 3, "hello world");
    
        display.join(); // see the text
    }
