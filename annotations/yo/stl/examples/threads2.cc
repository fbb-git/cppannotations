    #include <thread>
    #include <iostream>
    #include <unistd.h>
    
    using namespace std;
    
    // do not forget to use -lpthread with g++
    
    void fun(size_t count, char const *txt)
    {
    
        for (; count--; )
            cout << count << ": " << txt << endl;
    }
    
    int main()
    {                   // runs the threads following
                        // the object construction
        thread display(fun, 3, "hello world");
        display.detach();
    
        thread second(fun, 3, "a second thread");
        second.detach();
    
        cout << "leaving" << endl;
    }
