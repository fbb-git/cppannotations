    #include <iostream>
    #include <thread>
    
    void hello()
    {
        while (true)
            std::cout << "hello world!\n";
    }
    
    int main()
    {
        std::thread hi(hello);
    }

