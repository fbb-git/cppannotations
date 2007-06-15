    #include "autoptr2.h"

    int main(int argc, char **argv)
    {
        FBB::auto_ptr<char *> ap3(argv);
        return 0;
    }
