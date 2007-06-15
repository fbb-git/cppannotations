    #include "monitor.ih"

    void Monitor::run()
    {
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
                cout << "NEXT ...\n";

            }
            catch (char const *msg)
            {
                exiting(1, msg);
            }
        }
    }
