    #include <string>
    using namespace std;

    string *enlarge(string *old, unsigned oldsize, unsigned newsize)
    {
        string *tmp = new string[newsize];  // allocate larger array

        for (unsigned idx = 0; idx < oldsize; ++idx)
            tmp[idx] = old[idx];            // copy old to tmp

        delete[] old;                       // using [] due to objects

        return tmp;                         // return new array
    }

    int main()
    {
        string *arr = new string[4];        // initially: array of 4 strings

        arr = enlarge(arr, 4, 6);           // enlarge arr to 6 elements.
    }
