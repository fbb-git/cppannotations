    #include <iostream>
    using namespace std;

    void outOfMemory()
    {
        cout << "Memory exhausted. Program terminates." << endl;
        exit(1);
    }

    int main()
    {
        long allocated = 0;

        set_new_handler(outOfMemory);       // install error function

        while (true)                        // eat up all memory
        {
            new int [100000];
            allocated += 100000 * sizeof(int);
            cout << "Allocated " << allocated << " bytes\n";
        }
    }
