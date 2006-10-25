    #include "monitor.ih"

    void Monitor::run()
    {
//        signal(SIGCHLD, waitForChild);
        d_selector.addReadFd(STDIN_FILENO);

        while (true)
        {
            cout << "? " << flush;
            try
            {
                d_selector.wait();

                int fd;
                while ((fd = d_selector.readFd()) != -1)
                {
                    if (fd == STDIN_FILENO)
                        processInput();
                    else
                        processChild(fd);
                }
            }
            catch (...)
            {
                cerr << "select failed, exiting\n";
                exiting();
            }
        }
    }
