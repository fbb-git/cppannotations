    #include <iostream>
    #include <string>
    using namespace std;

    void outOfMemory()
    {
        cout << "Memory exhausted. Program terminates." << '\n';
        exit(1);
    }

    int main()
    {
        long allocated = 0;

        set_new_handler(outOfMemory);       // install error function

        while (true)                        // eat up all memory
        {
            memset(new int [100000], 0, 100000 * sizeof(int));
            allocated += 100000 * sizeof(int);
            cout << "Allocated " << allocated << " bytes\n";
        }
    }
