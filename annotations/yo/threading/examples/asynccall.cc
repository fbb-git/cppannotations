#include <iostream>
#include <future>
#include <string>

using namespace std;

class Object
{
    int d_value = 10;

    public:
        Object()
        {
            cout << "default cons\n";
        }

        Object(Object const &)
        {
            cout << "copy cons\n";
        }

        Object(Object &&)
        {
            cout << "move cons\n";
        }

        std::string member(int x, std::string const &str)
        {
            d_value = 133;
            return str;
        }
        int value() const
        {
            return d_value;
        }
};

int main()
{
    Object obj;

cout << "Calling\n";
    auto fut = async(launch::async,
                    &Object::member, 
                                    &obj, 
                                    
                                    133,  "hello world");

cout << "Getting\n";
    auto ret = fut.get();

    
    cout << "Text: " << ret << ", value: " << obj.value() << '\n';
}







