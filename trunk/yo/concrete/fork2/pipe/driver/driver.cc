/*
                              driver.cc

   $Id: driver.cc 33 2004-08-10 21:23:19Z frank $

   $Log$
   Revision 1.3  2004/08/10 21:23:18  frank
   Update to 6.0.0

   Revision 1.2  2003/07/19 09:18:28  frank
   Modifications related to version 5.2.1

   Revision 1.1.1.1  2003/05/27 19:11:04  frank
   C++ Annotations since 5.2.1

*/

#ifndef _INCLUDED_PIPE_H_
#include "../pipe.h"
#endif

#ifndef _INCLUDED_TYPES_H_
#include <sys/types.h>
#define _INCLUDED_TYPES_H_
#endif

#ifndef _INCLUDED_WAIT_H_
#include <sys/wait.h>
#define _INCLUDED_WAIT_H_
#endif

#ifndef _INCLUDED_UNISTD_H_
#include <unistd.h>
#define _INCLUDED_UNISTD_H_
#endif

#ifndef _INCLUDED_IOSTREAM_
#include <iostream>
#define _INCLUDED_IOSTREAM_
#endif

#ifndef _INCLUDED_STRING_
#include <string>
#define _INCLUDED_STRING_
#endif

using namespace std;
using namespace FBB;

int main(int argc, char **argv, char **envp)
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
