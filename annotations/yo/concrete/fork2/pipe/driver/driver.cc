/*
                              driver.cc

*/

#include "../pipe.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    Pipe p;                         // construct a pipe

    cout << "Read file descriptor: " << p.readFd() << '\n';
    cout << "Write file descriptor: " << p.writeFd() << '\n';

    int pid = fork();

    if (pid == -1)
        return 1;

    if (!pid)                       //child
    {
        p.readVia(STDIN_FILENO);    // read what goes into the pipe from cin

        string s;

        getline(cin, s);

        cout << "Got: " << s << '\n';

        getline(cin, s);

        cout << "Got: " << s << '\n';

        return 0;
    }

    int stdfd[] = {STDOUT_FILENO, STDERR_FILENO};

    p.writeVia(stdfd);      // write to the pipe via cout

    cout << "first line" << '\n';
    cerr << "second line" << '\n';

    waitpid(pid, 0, 0);
}
