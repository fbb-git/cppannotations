    #include <iostream>
    #include <string>
    #include <functional>
    #include <numeric>
    using namespace std;

    int main(int argc, char **argv)
    {
        string result =
                accumulate(argv, argv + argc, string(), plus<string>());

        cout << "All concatenated arguments: " << result << '\n';
    }
