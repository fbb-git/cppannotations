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

    cout << "Read file descriptor: " << p.readFd() << endl;
    cout << "Write file descriptor: " << p.writeFd() << endl;

    int pid = fork();

    if (pid == -1)
        return 1;

    if (!pid)                       //child
    {
        p.readVia(STDIN_FILENO);    // read what goes into the pipe from cin

        string s;

        getline(cin, s);

        cout << "Got: " << s << endl;

        getline(cin, s);

        cout << "Got: " << s << endl;

        return 0;
    }

    int stdfd[] = {STDOUT_FILENO, STDERR_FILENO};

    p.writeVia(stdfd);      // write to the pipe via cout

    cout << "first line" << endl;
    cerr << "second line" << endl;

    waitpid(pid, 0, 0);

    return 0;
}
