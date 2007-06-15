#include <iostream>
#include <string>
#include <queue>

int main()
{
    queue<string>
        q;

    q.push("Hello");
    q.front() = "Hello World";

    cout << q.front() << endl;

    return (0);
}
