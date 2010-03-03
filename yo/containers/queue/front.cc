#include <iostream>
#include <string>
#include <queue>

int main()
{
    queue<string>
        q;

    q.push("Hello");
    q.front() = "Hello World";

    cout << q.front() << '\n';

    return (0);
}
