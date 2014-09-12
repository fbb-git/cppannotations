    #include <thread>
    #include <iostream>
    #include <chrono>

    void fun(size_t count, char const *txt)
    {
        for (; count--; )
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << count << ": " << txt << std::endl;
        }
    }

    int main()
    {
        std::thread first(fun, 5, "hello world");
        first.detach();

        std::thread second(fun, 5, "a second thread");
        second.detach();

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "leaving" << std::endl;
    }
