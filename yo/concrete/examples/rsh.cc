    #include <iostream>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <string>

    int main()
    {
        while (true)
        {
            string
                cmd;

            cout << "rsh: " << flush;
            cin >> cmd;

            if (cmd == "exit")
            {
                cout << "terminating the shell\n";
                return 0;
            }

            if (cmd == "date" || cmd == "id")
            {
                pid_t
                    pid = fork();

                if (pid == 0)
                {
                    execlp(cmd.c_str(), cmd.c_str(), 0);
                    cerr << "Execution of " << cmd << " failed\n";
                    return 1;
                }

                if (pid < 0)
                {
                    cerr << "Fork() failed\n";
                    return 1;
                }

                int
                    status;
                wait(&status);
                if ((status = WEXITSTATUS(status)))
                    cerr << cmd << " returned exit status " << status << '\n';
            }
            else
                cout << "Command " << cmd << " disallowed\n";
        }
    }
    /*
        Example of generated conversation:
    rsh: opa
    Command opa disallowed
    rsh: date
    Tue Jul 17 23:19:08 CEST 2001
    rsh: id
    uid=405(frank) gid=100(users) groups=100(users),4(adm)
    rsh: quit
    Command quit disallowed
    rsh: exit
    terminating the shell
    */
